import 'package:flutter/material.dart';
import 'package:get/get.dart';
import '../pages/upload.dart';

enum PageName { HOME, SEARCH, UPLOAD, ACTIVITY, MYPAGE }

// 페이지 인덱스 관리
class BottomNavcontroller extends GetxController {
  RxInt pageIndex = 0.obs;
  List<int> bottomHistory = [0];

  void changeBottomNav(int value) {
    var page = PageName.values[value];
    switch (page) {
      case PageName.UPLOAD:
        Get.to(() => const Upload());
        break;
      case PageName.HOME:
      case PageName.SEARCH:
      case PageName.ACTIVITY:
      case PageName.MYPAGE:
        _changePage(value);
        break;
    }
    pageIndex(value);
  }

  void _changePage(int value) {
    pageIndex(value);
  }

  Future<bool> willPopAction() async {
    if (bottomHistory.length == 1) {
      print('exit');
      return false;
    } else {
      print("goto befo page!");
      return true;
    }
  }
}
