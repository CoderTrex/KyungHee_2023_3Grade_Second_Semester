import 'dart:js_util';

import 'package:flutter/material.dart';
import 'package:get/get.dart';
import 'src/App.dart';
import 'src/binding/init_bindings.dart';

void main() {
  runApp(const MyApp());
}

// class MyApp extends StatelessWidget {
//   const MyApp({Key? key}) : super(key: key);
//   // This widget is the root of your application.
//   @override
//   Widget build(BuildContext context) {
//     return GetMaterialApp(
//       title: 'Flutter Demo',
//       theme: ThemeData(
//         primarySwatch: Colors.blue,
//         appBarTheme: const AppBarTheme(
//           backgroundColor: Colors.white,
//           titleTextStyle: TextStyle(color: Colors.black),
//         ),
//       ),
//       initialBinding: InitBinding(),
//       home: const App(),
//     );
//   }
// }

// import 'package:flutter/material.dart';

class MyApp extends StatelessWidget {
  MyApp({super.key});
  final Map info = {
    'appTitle': 'StatelessWidget Demo',
    'appBarTitle': 'Flutter Official Site',
    'titleImageLink': 'https://storage.googleapis.com/cms-storage-bucket/'
        '2f118a9971e4ca6ad737.png',
    'titleSectionHeader': 'Flutter on Mobile',
    'titleSectionBody': 'https://flutter.dev/multi-platform/mobile',
    'titleSectionScore': 100,
    'textSection': 'Bring your app idea to more users from day one by'
        ' building with Flutter '
        'on iOS and Android simultaneously, without sacrificing features, '
        'quality, or performance. All mobile on day one: '
        'Reach your full addressable market from day one by targeting users'
        ' in both ecosystems from a single codebase. Do more with less: '
        'Unite your mobile development team resources towards building '
        'one seamless customer experience. One experience: '
        'Release simultaneously on iOS and Android with feature parity '
        'for the best experience for all users.',
  };

  @override
  Widget build(BuildContext context) {
    final titleImage = _buildTitleImage(info['titleImageLink']);
    Widget textSection = _buildTextSection(info['textSection']);
    Widget buttonSection = _buildButtonSection(Theme.of(context).primaryColor);
    Widget titleSection = _buildTitleSection(info['titleSectionHeader'],
        info['titleSectionBody'], info['titleSectionScore']);

    return MaterialApp(
      title: info['apptitle'],
      home: Scaffold(
        appBar: AppBar(
          title: Text(info['appBarTitle']),
        ),
        body: ListView(
          children: [titleImage, titleSection, buttonSection, textSection],
        ),
      ),
    );
  }
}

Image _buildTitleImage(String lk_image) {
  return Image.network(lk_image, width: 600, height: 240, fit: BoxFit.cover);
}

Container _buildTitleSection(String name, String addr, int count) {
  return Container(
    child: Row(
      children: [
        Expanded(
          child: Column(
            crossAxisAlignment: CrossAxisAlignment.start,
            children: [
              Container(
                padding: const EdgeInsets.only(bottom: 8),
                child: Text(
                  name,
                  style: const TextStyle(
                    fontWeight: FontWeight.bold,
                  ),
                ),
              ),
              Text(
                addr,
                style: TextStyle(
                  color: Colors.grey[500],
                ),
              ),
            ],
          ),
        ),
        Icon(
          Icons.star,
          color: Colors.red[500],
        ),
        Text('$count'),
      ],
    ),
  );
}

Widget _buildButtonSection(Color color) {
  return Row(
    mainAxisAlignment: MainAxisAlignment.spaceEvenly,
    children: [
      _buildButtonColumn(color, Icons.assistant_navigation, 'Visit'),
      _buildButtonColumn(color, Icons.add_alarm_rounded, 'Alarm'),
      _buildButtonColumn(color, Icons.share, 'Share'),
    ],
  );
}

Column _buildButtonColumn(Color color, IconData icon, String label) {
  return Column(
    mainAxisSize: MainAxisSize.min,
    mainAxisAlignment: MainAxisAlignment.center,
    children: [
      Icon(icon, color: color),
      Container(
        margin: const EdgeInsets.only(top: 8),
        child: Text(
          label,
          style: TextStyle(
              fontSize: 13, fontWeight: FontWeight.w500, color: color),
        ),
      )
    ],
  );
}

Container _buildTextSection(String section) {
  return Container(
    padding: const EdgeInsets.all(32),
    child: Text(
      section,
      softWrap: true,
      textAlign: TextAlign.justify,
      style: const TextStyle(height: 1.5, fontSize: 15),
    ),
  );
}
