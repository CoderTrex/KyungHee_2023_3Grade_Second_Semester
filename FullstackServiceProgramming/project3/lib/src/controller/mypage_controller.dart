import 'package:get/get.dart';
import 'package:flutter/material.dart';
import 'package:project/src/controller/auth_controller.dart';
import 'package:project/src/models/project_user_.dart';

// class MyPageController extends GetxController with GetTickerProviderStateMixin {
//   late TabController tabController;
//   Rx<Puser> targetUser = Puser().obs;

//   @override
//   void onInit() {
//     super.onInit();
//     tabController = TabController(length: 2, vsync: this);
//     _loadData();
//   }

//   void setTargetUser() {
//     var uid = Get.parameters['targetUid'];
//     if (uid == null) {
//       targetUser(AuthController.to.user.value);
//     } else {
//       // Todo 상대 uid로 users collection을 조회
//     }
//   }

//   void _loadData() {
//     setTargetUser();

//     // 포스트 라스트 데이터
//     // 사용자 정보 로드
//   }
// }

class MyPageController extends GetxController with GetTickerProviderStateMixin {
  late TabController tabController;
  Rx<Puser> targetUser = Puser().obs;

  @override
  void onInit() {
    super.onInit();
    tabController = TabController(length: 2, vsync: this);
    _loadData();
  }

  void setTargetUser() {
    var uid = Get.parameters['targetUid'];
    if (uid == null) {
      targetUser(AuthController.to.user.value);
    } else {
      //TODO 상대 uid 로 users collection 조회
    }
  }

  void _loadData() {
    setTargetUser();

    // 포스트 리스트 로드
    // 사용자 정보 로드
  }
}
