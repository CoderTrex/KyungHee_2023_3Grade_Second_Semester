import 'package:get/get.dart';
import 'package:project/src/models/project_user_.dart';
import 'package:project/src/repository/user_repository.dart';

class AuthController extends GetxController {
  static AuthController get to => Get.find();

  Rx<Puser> user = Puser().obs;

  Future<Puser?> loginUser(String uid) async {
    var userdata = UserRepository.loginUserByUid(uid);
    // print(userdata);
    return userdata;
  }

  void signup(Puser signupUser) async {
    var result = await UserRepository.signup(signupUser);
    if (result) {
      user(signupUser);
    }
    // return result;
  }
}
