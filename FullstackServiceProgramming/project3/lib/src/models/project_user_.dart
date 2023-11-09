class Puser {
  String? uid; // user uid
  String? nickname; // nickname in application
  String? thumbnail; // User profile image
  String? description; // One-line user introduction

  // User’s individual subscription list and algorithm
  final List<Map<dynamic, bool>> subcrible = [];
  final List<Map<dynamic, int>> interest = [];
  final List<Map<dynamic, int>> algorithm = [];

  Puser({
    this.uid,
    this.nickname,
    this.thumbnail,
    this.description,
  });

  factory Puser.fromJson(Map<String, dynamic> json) {
    return Puser(
      uid: json['uid'] == null ? '' : json['uid'] as String,
      nickname: json['nickname'] == null ? '' : json['nickname'] as String,
      thumbnail: json['thumbnail'] == null ? '' : json['thumbnail'] as String,
      description:
          json['description'] == null ? '' : json['description'] as String,
    );
  }

  Map<String, dynamic> toMap() {
    return {
      'uid': uid,
      'nickname': nickname,
      'thumbnail': thumbnail,
      'description': description,
    };
  }

  Puser copyWith({
    String? uid,
    String? nickname,
    String? thumbnail,
    String? description,
  }) {
    return Puser(
      uid: uid ?? this.uid,
      nickname: nickname ?? this.nickname,
      thumbnail: thumbnail ?? this.thumbnail,
      description: description ?? this.description,
    );
  }
}
