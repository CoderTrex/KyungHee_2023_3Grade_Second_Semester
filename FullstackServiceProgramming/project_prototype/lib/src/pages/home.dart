import 'package:cached_network_image/cached_network_image.dart';
import 'package:flutter/material.dart';
import 'package:project/src/App.dart';
import 'package:project/src/components/avatar_widget.dart';
import 'package:project/src/components/image_dart.dart';
import 'package:project/src/components/post_widget.dart';

class Home extends StatelessWidget {
  const Home({super.key});

  Widget _advertiseList() {
    return SizedBox(
      height: 250.0, // 광고 높이 설정
      child: PageView(
        scrollDirection: Axis.horizontal, // 가로 스크롤
        children: [
          Image.network(
            'https://cdn.dailysportshankook.co.kr/news/photo/202203/255434_254769_2938.jpg',
          ),
          Image.network(
            'https://i.pinimg.com/originals/a7/d3/5d/a7d35df76a0c4f4ef951fb610d5f706a.jpg',
          ),
          Image.network(
              'https://www.sisajournal-e.com/news/photo/202001/212755_75038_4155.jpg'),
          // 추가 광고 이미지를 필요한 만큼 여기에 추가
        ],
      ),
    );
  }

  Widget _myStory() {
    return Stack(
      children: [
        AvatarWidget(
          type: AvatarType.TYPE2,
          thumbPath:
              'https://img.hankyung.com/photo/202306/AKR20230630015400005_02_i_P4.jpg',
          size: 70,
        ),
        Positioned(
          right: 5,
          bottom: 0,
          child: Container(
            width: 25,
            height: 25,
            decoration: BoxDecoration(
              shape: BoxShape.circle,
              color: Colors.blue,
              border: Border.all(
                color: Colors.white,
                width: 2,
              ),
            ),
            child: const Center(
              child: Text(
                '+',
                style: TextStyle(
                  fontSize: 20,
                  color: Colors.white,
                  height: 1.1,
                ),
              ),
            ),
          ),
        )
      ],
    );
  }

  Widget _storyBoardList() {
    return SingleChildScrollView(
      scrollDirection: Axis.horizontal,
      child: Row(
        children: [
          const SizedBox(width: 20),
          _myStory(),
          const SizedBox(width: 5),
          ...List.generate(
            1,
            (index) => AvatarWidget(
              type: AvatarType.TYPE1,
              thumbPath:
                  'https://seeklogo.com/images/W/webtoon-logo-F208928254-seeklogo.com.png',
            ),
          ),
          ...List.generate(
            1,
            (index) => AvatarWidget(
              type: AvatarType.TYPE1,
              thumbPath:
                  'https://upload.wikimedia.org/wikipedia/commons/8/8f/Kakao_page_logo.png',
            ),
          ),
          ...List.generate(
            1,
            (index) => AvatarWidget(
              type: AvatarType.TYPE1,
              thumbPath:
                  'https://upload.wikimedia.org/wikipedia/commons/e/ef/Youtube_logo.png?20220706172052',
            ),
          ),
          ...List.generate(
            1,
            (index) => AvatarWidget(
              type: AvatarType.TYPE1,
              thumbPath:
                  'https://cdn.vox-cdn.com/thumbor/pNxD2NFOCjbljnMPUSGdkFWeDjI=/0x0:3151x2048/1400x788/filters:focal(1575x1024:1576x1025)/cdn.vox-cdn.com/uploads/chorus_asset/file/15844974/netflixlogo.0.0.1466448626.png',
            ),
          ),
        ],
      ),
    );
  }

  Widget _postList() {
    return Column(
      children: List.generate(1, (index) => PostWidget()).toList(),
    );
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        elevation: 10,
        title: ImageData(
          IconsPath.logo,
          width: 300,
        ),
      ),
      body: ListView(children: [
        _advertiseList(),
        const SizedBox(height: 50),
        _storyBoardList(),
        _postList(),
      ]),
    );
  }
}
