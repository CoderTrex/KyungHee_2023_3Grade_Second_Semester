import 'package:flutter/material.dart';

class App extends StatelessWidget {
  const App({super.key});

  @override
  Widget build(BuildContext context) {
    return WillPopScope(
      child: Scaffold(
        appBar:AppBar(),
        body: Container(),
        bottomNavigationBar: BottomNavigationBar(
          items: [BottomNavigationBarItem(icon: Image.assets('name'))],
        ),
      ),
      onWillPop: () async{
        return false;
      }
    );
  }
}
