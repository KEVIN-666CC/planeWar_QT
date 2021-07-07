#ifndef CONFIG_H
#define CONFIG_H
/********* 游戏资源 **************/
#define GAME_RES_PATH "./plane.rcc" //rcc文件路径
/********** 游戏配置数据 **********/
#define GAME_WIDTH 800 //宽度
#define GAME_HEIGHT 1000 //高度
#define GAME_TITLE "飞行射击小游戏" //标题
#define GAME_ICON ":/Resource/app.ico"//游戏图标
/********** 地图配置数据 **********/
#define MAP_PATH ":/Resource/img_bg_level_3.png" //地图图片路径
#define MAP_SCROLL_SPEED 2 //地图滚动速度
#define GAME_RATE 10 //定时器刷新时间间隔，帧率 单位毫秒
/********** 游戏主菜单 **********/
#define START_PAGE ":/Resource/wallpapersden.com_k-league-of-legends-2020_1920x1080.jpg"//界面背景图
#define GAME_BIG_NAME ":/Resource/1623499472_961730.png"//游戏大名
#define START_BTN ":/Resource/1623480751_289411.png"//开始按钮
#define HELP_BTN ":/Resource/1623480771_412410.png"//帮助按钮
#define QUIT_BTN ":/Resource/1623480604_616941.png"//结束按钮
/********** 游戏help界面**********/
#define GAME_INTRO1 ":/Resource/1623497252_282414.png" //第一排字
#define GAME_INTRO2 ":/Resource/1623497374_924849.png"//第二排字
#define GAME_INTRO3 ":/Resource/1623497521_506330.png"//第三排字
#define GAME_INTRO4 ":/Resource/1623497595_803765.png"//第四排字
#define HELP_PAGE ":/Resource/wallpapersden.com_k-league-of-legends-2020_1920x1080-2.jpg"//界面背景图
#define RETURN_BTN ":/Resource/1623484615_969643.png"//返回按钮
/********** 飞机配置数据 **********/
#define HERO_PATH ":/Resource/hero2.png"//飞机图案
/********** 子弹配置数据 **********/
#define BULLET_PATH ":/Resource/hero_bullet_7.png" //子弹图片路径
#define BULLET_SPEED 25 //子弹移动速度
#define BULLET_NUM 30 //弹匣中子弹总数
#define BULLET_INTERVAL 28 //发射子弹时间间隔
/********** 敌机配置数据 **********/
#define ENEMY_PATH ":/Resource/img-plane_5.png" //敌机资源图片
#define ENEMY_SPEED 4 //敌机移动速度
#define ENEMY_NUM 20 //敌机总数量
#define ENEMY_INTERVAL 25 //敌机出场时间间隔
/************* 爆炸效果 ****************/
#define BOMB_PATH ":/Resource/bomb-%1.png" //爆炸资源图片
#define BOMB_NUM 20 //爆炸数量
#define BOMB_MAX 7 //爆炸图片最大索引
#define BOMB_INTERVAL 10 //爆炸切图时间间隔
/************ 播放音效 ***********/
#define SOUND_BOMB ":/Resource/bomb.wav" //打中敌机的炮声
/********** GAME OVER 界面 ***********/
#define RETURN_MENU_BTN ":/Resource/1623498125_442436.png"//返回菜单按钮
#define EXIT_BTN ":/Resource/1623498144_673911.png"//退出按钮
#endif // CONFIG_H
