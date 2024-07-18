CREATE TABLE `CookieChargeHistory` (
	`쿠키충전기록아이디`	BIGINT	NOT NULL,
	`쿠키충전양`	INT	NULL,
	`생성일자`	DATETIME	NULL,
	`수정일자`	DATETIME	NULL,
	`회원아이디`	BIGINT	NOT NULL,
	`구매 작품 목록`	VARCHAR	NULL,
	`지불금액`	INT	NULL
);

ALTER TABLE `CookieChargeHistory` ADD CONSTRAINT `PK_COOKIECHARGEHISTORY` PRIMARY KEY (
	`쿠키충전기록아이디`
);



-- -> 수정 진행

CREATE TABLE `CookieChargeHistoryInfo` (
	`쿠키충전기록아이디`	BIGINT	NOT NULL,
	`쿠키충전양`	INT	NULL,
	`생성일자`	DATETIME	NULL,
	`수정일자`	DATETIME	NULL,
	`회원아이디`	BIGINT	NOT NULL
);

CREATE TABLE `PaymentInfo` (
	`쿠키충전기록아이디`	BIGINT	NULL,
	`구매 작품 목록`	VARCHAR	NULL,
	`지불금액`	INT	NULL
);

ALTER TABLE `CookieChargeHistoryInfo` ADD CONSTRAINT `PK_COOKIECHARGEHISTORYINFO` PRIMARY KEY (
	`쿠키충전기록아이디`
);

ALTER TABLE `PaymentInfo` ADD CONSTRAINT `PK_PAYMENTINFO` PRIMARY KEY (
	`쿠키충전기록아이디`,
	`구매 작품 목록`
);