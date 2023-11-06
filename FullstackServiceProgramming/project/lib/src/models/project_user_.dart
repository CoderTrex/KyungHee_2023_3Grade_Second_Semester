class Puser {
  String? uid;
  String? nickname;
  String? thumnail;
  String? description;

  Puser({
    this.uid,
    this.nickname,
    this.thumnail,
    this.description,
  });

  factory Puser.fromJson(Map<String, dynamic> json) {
    return Puser(
      uid: json['uid'] == null ? ' ' : json['uid'] as String,
      nickname: json['nickname'] == null ? ' ' : json['nickname'] as String,
      thumnail: json['thumbnail'] == null ? ' ' : json['thumbnail'] as String,
      description:
          json['description'] == null ? ' ' : json['description'] as String,
    );
  }

  Map<String, dynamic> toMap() {
    return {
      'uid': uid,
      'nickname': nickname,
      'thumnail': thumnail,
      'description': description,
    };
  }
}
