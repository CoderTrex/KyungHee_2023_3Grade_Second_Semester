const axios = require('axios');

// API 요청에 필요한 매개변수 설정
const baseURL = 'https://korea-webtoon-api.herokuapp.com';
const params = {
  page: 0, // 페이지 번호
  perPage: 100, // 한 페이지 결과 수
  service: 'naver', // 웹툰 공급자 (naver, kakao, kakaoPage)
  updateDay: 'sun', // 웹툰 업데이트 구분
};

// API 요청
axios.get(baseURL, { params })
  .then(response => {
    const webtoonData = response.data;
    console.log('웹툰 정보:', webtoonData);

    // 여기에서 웹툰 정보를 원하는 방식으로 처리할 수 있습니다.
  })
  .catch(error => {
    console.error('API 요청 중 에러 발생:', error);
});
