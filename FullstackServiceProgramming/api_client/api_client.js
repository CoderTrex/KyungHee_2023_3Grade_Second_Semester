const mongoose = require('mongoose');
const axios = require('axios');

// 웹툰 모델 정의
const webtoonSchema = new mongoose.Schema({
    webtoonId: Number, // webtoonId 필드 추가
    title: String,
    author: String,
    url: String,
    img: String,
    service: String,
    updateDays: [String],
    // 기타 필요한 필드 추가
});

const Webtoon = mongoose.model('Webtoon', webtoonSchema);
// MongoDB 연결 설정

mongoose.connect('mongodb://localhost:27017/fspdb_api_kw_api', { useNewUrlParser: true, useUnifiedTopology: true });
const db = mongoose.connection;

db.on('error', console.error.bind(console, 'MongoDB 연결 오류:'));

db.once('open', () => {
  console.log('MongoDB에 연결되었습니다.');

  // API 요청
  const baseURL = 'https://korea-webtoon-api.herokuapp.com';
  const params = {
    page: 0, // 페이지 번호
    perPage: 1, // 한 페이지 결과 수
    service: 'kakao', // 웹툰 공급자 (naver, kakao, kakaoPage)
    updateDay: 'sun', // 웹툰 업데이트 구분
  };

  axios.get(baseURL, { params })
    .then(response => {
      const webtoonData = response.data;

      // 웹툰 정보를 MongoDB에 저장
      const savePromises = webtoonData.webtoons.map(webtoonInfo => {
        // 중복 데이터 확인 및 업데이트
        const query = { webtoonId: webtoonInfo.webtoonId };
        const update = { $set: webtoonInfo };
        
        return Webtoon.findOneAndUpdate(query, update, { upsert: true, new: true }).exec();
      });

      Promise.all(savePromises)
        .then(savedWebtoons => {
            // savePromises.savePromises(),
          console.log('데이터가 MongoDB에 저장되었습니다:', savedWebtoons);
        })
        .catch(err => {
          console.error('데이터 저장 중 에러 발생:', err);
        });
    })
    .catch(error => {
      console.error('API 요청 중 에러 발생:', error);
    });
});

module.exports = Webtoon;
