import 'package:get/get.dart';
import 'package:project/src/controller/bottom_nav_controller.dart';

class InitBinding extends Bindings{
  @override
  void dependencies(){
    Get.put(BottomNavcontroller(), permanent: true);
  }
}