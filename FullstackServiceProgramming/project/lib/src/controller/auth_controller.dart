import 'dart:io';

import 'package:firebase_storage/firebase_storage.dart';
import 'package:get/get.dart';
import 'package:image_picker/image_picker.dart';
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

  void signup(Puser signupUser, XFile? thumbnail) async {
    if (thumbnail == null) {
      _submitSignup(signupUser);
    } else {
      // thumbnail.path.split('.').last;
      var task = UploadXFile(thumbnail,
          '${signupUser.uid}/profile.${thumbnail.path.split('.').last}');
      task.snapshotEvents.listen(
        (event) {
          print(event.bytesTransferred);
          if (event.totalBytes == event.bytesTransferred &&
              event.state == TaskState.success) {
            var downloadUrl = event.ref.getDownloadURL();
            var updateUserData = signupUser.copyWith(thumbnail:downloadUrl)
          }
        },
      );
    }
  }

  UploadTask UploadXFile(XFile file, String filename) {
    var f = File(file.path);
    var ref = FirebaseStorage.instance.ref().child('users').child(filename);
    final metadata = SettableMetadata(
      contentType: 'image/jpeg',
      customMetadata: {'picked-file-path': file.path},
    );
    return ref.putFile(f, metadata);
    // users /{uid}/profile.jgp 과같은 형식으로 저장됨
  }

  void _submitSignup(Puser signupUser) async {
    var result = await UserRepository.signup(signupUser);
    if (result) {
      user(signupUser);
    }
    // return result;
  }
}
