// import 'package:firebase_core/firebase_core.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:flutter/material.dart';
import 'package:project/src/App.dart';
import 'package:project/src/pages/login.dart';

class Root extends StatelessWidget {
  const Root({super.key});

  @override
  Widget build(BuildContext context) {
    return StreamBuilder(
      stream: FirebaseAuth.instance.authStateChanges(),
      // initialData: initialData,
      builder: (BuildContext _, AsyncSnapshot<User?> user) {
        if (user.hasData)
          return const App();
        else {
          return const Login();
        }
        // child: child,
      },
    );
  }
}
