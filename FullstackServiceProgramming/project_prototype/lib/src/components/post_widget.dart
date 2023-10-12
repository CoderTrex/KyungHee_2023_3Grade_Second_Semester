import 'package:cached_network_image/cached_network_image.dart';
import 'package:expandable_text/expandable_text.dart';
import 'package:flutter/material.dart';
import 'package:project/src/components/avatar_widget.dart';
import 'package:project/src/components/image_dart.dart';

class PostWidget extends StatelessWidget {
  const PostWidget({super.key});

  Widget _title1() {
    return const Padding(
      padding: EdgeInsets.symmetric(horizontal: 15.0),
      child: Text(
        '네이버 웹툰',
        style: TextStyle(
          color: Colors.black,
          fontSize: 14,
        ),
      ),
    );
  }

  Widget _content1(BuildContext context) {
    double size_w = 100, size_h = 130.0;
    List<String> imageUrls = [
      'https://i.namu.wiki/i/KKs50nVvhF1XhiwYhrpU0LGkzxdhU_hLlACNBCfn8Sz5iEAb-FSnGTQa8pkbmnZUxiEWjVdJDRARcCZSf_w2BA.webp',
      'https://i.namu.wiki/i/AlXbPNwzOBGpJpYnzmQu_De4FRe0b6zYghymMpr0U0cf-i0CDD6AbBoZpldIJYHrZ_T1L2_NMfg1Gg__xbz8jw.webp',
      'https://i.namu.wiki/i/ZkfF8ET1MacLdodY9mtgG16xb8OZxu11fwZQiTJqo8DFE-tZQ3p3ghcKlRSs0NpzUGcFSdzHfTAxUwRHqcIGqQ.webp',
      'https://i.namu.wiki/i/YxlqtX72KtWDxePGIVT9Z3KJhGOsyQaM-ngOaleCLhLRzJ4mpnYKLRdSDhoGS0h8JqgJbjtE1iVLpJXjkYarsw.webp',
      'https://comicthumb-phinf.pstatic.net/20201221_57/pocket_1608530248666JkFfN_JPEG/__690x100.jpg',
    ];

    return SingleChildScrollView(
      scrollDirection: Axis.horizontal, // 가로 스크롤
      child: Row(
        children: [
          for (String imageUrl in imageUrls)
            Padding(
              padding: EdgeInsets.only(left: 30.0), // 이미지 사이의 간격을 조절
              child: Stack(
                children: [
                  Align(
                    alignment: Alignment.centerLeft,
                    child: Image(
                      image: CachedNetworkImageProvider(imageUrl),
                      width: size_w, // 원하는 폭 (픽셀) 설정
                      height: size_h, // 원하는 높이 (픽셀) 설정
                      fit: BoxFit.fill,
                    ),
                  ),
                ],
              ),
            ),
        ],
      ),
    );
  }

  Widget _content2(BuildContext context) {
    double size_w = 142, size_h = 80;
    List<String> imageUrls = [
      'https://datasets-server.huggingface.co/assets/daspartho/mrbeast-thumbnails/--/default/train/5/image/image.jpg',
      'https://i.ytimg.com/vi/hnanNlDbsE4/maxresdefault.jpg',
      'https://i.ytimg.com/vi/R6-HrA0dhr4/maxresdefault.jpg',
    ];

    return SingleChildScrollView(
      scrollDirection: Axis.horizontal, // 가로 스크롤
      child: Row(
        children: [
          for (String imageUrl in imageUrls)
            Padding(
              padding: EdgeInsets.only(left: 30.0), // 이미지 사이의 간격을 조절
              child: Align(
                alignment: Alignment.centerLeft,
                child: Image(
                  image: CachedNetworkImageProvider(imageUrl),
                  width: size_w, // 원하는 폭 (픽셀) 설정
                  height: size_h, // 원하는 높이 (픽셀) 설정
                  fit: BoxFit.fill,
                ),
              ),
            ),
        ],
      ),
    );
  }

  Widget _header() {
    return Padding(
      padding: const EdgeInsets.symmetric(horizontal: 15.0),
      child: Row(
        mainAxisAlignment: MainAxisAlignment.spaceBetween,
        children: [
          AvatarWidget(
            type: AvatarType.TYPE3,
            nickname: 'silvercastle',
            size: 40,
            thumbPath:
                'https://img.hankyung.com/photo/202306/AKR20230630015400005_02_i_P4.jpg',
          ),
          GestureDetector(
            onTap: () {},
            child: Padding(
              padding: const EdgeInsets.all(8.0),
              child: ImageData(
                IconsPath.postMoreIcon,
                width: 30,
              ),
            ),
          )
        ],
      ),
    );
  }

  Widget _image() {
    return CachedNetworkImage(
        imageUrl:
            'https://image.webtoonguide.com/b2/5b/14699fe054e3e4ecc8de4ac4d1f4');
  }

  Widget _infoCount() {
    return Padding(
      padding: const EdgeInsets.symmetric(horizontal: 15.0),
      child: Row(
        mainAxisAlignment: MainAxisAlignment.spaceBetween,
        children: [
          Row(
            children: [
              ImageData(
                IconsPath.likeOffIcon,
                width: 65,
              ),
              const SizedBox(width: 15),
              ImageData(
                IconsPath.replyIcon,
                width: 60,
              ),
              const SizedBox(width: 15),
              ImageData(
                IconsPath.directMessage,
                width: 55,
              )
            ],
          ),
          ImageData(
            IconsPath.bookMarkOffIcon,
            width: 50,
          )
        ],
      ),
    );
  }

  Widget _infoDescription() {
    return Padding(
      padding: const EdgeInsets.symmetric(horizontal: 15.0),
      child: Column(
        crossAxisAlignment: CrossAxisAlignment.stretch,
        children: [
          const Text(
            '좋아요 150개',
            style: TextStyle(
              fontWeight: FontWeight.bold,
            ),
          ),
          ExpandableText(
            '눈이 온다~\n눈이 온다~\n눈이 온다~\n눈이 온다~\n',
            prefixText: 'silvercastle',
            onPrefixTap: () {
              print('세기말 풋사과 보습학원 보러가기~');
            },
            prefixStyle: const TextStyle(fontWeight: FontWeight.bold),
            expandText: '더보기',
            collapseText: '접기',
            maxLines: 3,
            expandOnTextTap: true,
            collapseOnTextTap: true,
            linkColor: Colors.grey,
          ),
        ],
      ),
    );
  }

  Widget _replyTextBtn() {
    return GestureDetector(
      onTap: () {},
      child: const Padding(
        padding: EdgeInsets.symmetric(horizontal: 15.0),
        child: Text(
          '댓글 30개 모두 보기',
          style: TextStyle(color: Colors.grey, fontSize: 13),
        ),
      ),
    );
  }

  Widget _dateAgo() {
    return const Padding(
      padding: EdgeInsets.symmetric(horizontal: 15.0),
      child: Text(
        '1일전',
        style: TextStyle(
          color: Colors.grey,
          fontSize: 13,
        ),
      ),
    );
  }

  @override
  Widget build(BuildContext context) {
    return Container(
      margin: const EdgeInsets.only(top: 20),
      child: Column(
        crossAxisAlignment: CrossAxisAlignment.stretch,
        children: [
          const SizedBox(height: 20),
          _content1(context),
          const SizedBox(height: 50),
          _content2(context),
          const SizedBox(height: 55),
          _header(),
          const SizedBox(height: 15),
          _image(),
          const SizedBox(height: 15),
          _infoCount(),
          const SizedBox(height: 5),
          _infoDescription(),
          const SizedBox(height: 5),
          _replyTextBtn(),
          const SizedBox(height: 5),
          _dateAgo(),
        ],
      ),
    );
  }
}
