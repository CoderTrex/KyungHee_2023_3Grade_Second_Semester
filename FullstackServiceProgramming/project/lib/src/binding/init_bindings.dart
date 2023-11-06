import 'package:get/get.dart';
import '../controller/auth_controller.dart';
import 'package:project/src/controller/bottom_nav_controller.dart';

class InitBinding extends Bindings {
  @override
  void dependencies() {
    Get.put(BottomNavcontroller(), permanent: true);
    Get.put(AuthController(), permanent: true);
  }
}
