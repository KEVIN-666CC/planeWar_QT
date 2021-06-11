#ifndef CONFIG_H
#define CONFIG_H

//游戏数据
#define GAME_Width 512  //宽度
#define GAME_Heigth 768  //高度
#define GAME_Title "飞机大战" //窗口标题
#define GAME_ICON ":/res/app.ico"

#define GAME_Rate 10  //定时器刷新间隔  毫秒

//地图配置数据
#define Map_Path  ":/res/img_bg_level_2.jpg"  //地图背景图
#define Map_Scroll_Speed 2 //地图滚动速度


//飞机配置数据
#define Plane_Model ":/res/hero.png"

//子弹数据
#define bullet_model ":/res/bullet_11.png" //子弹模型
#define BULLET_SPEED 5  //子弹速度
#define bullet_num 30 //子弹数量
#define bullet_interval 20 //子弹发射间隔

//敌机数据
#define  enemyplane_model   ":/res/img-plane_7.png"
#define ENEMY_SPEED 3
#define ENEMY_NUM 50
#define ENEMY_INTERVAL 30

//爆炸效果
#define Bomb_model ":/res/bomb-%1.png"
#define Bomb_NUM 20 //爆炸数量
#define Bomb_max 7 //爆炸图片最大索引
#define Bomb_Interval 10//爆炸切图时间间隔

//#define BombHero  1000

//音效
#define Sound_backgroud "‪:/res/bg.wav" //‪D:\qt\PlaneWar\res\bg.wav中斜杠反向
#define Sound_bomb "/:res/bomb.wav"

#endif // CONFIG_H
