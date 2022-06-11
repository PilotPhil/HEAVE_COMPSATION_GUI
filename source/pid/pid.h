#ifndef PID_H
#define PID_H

#include <QObject>

class PID : public QObject {
  Q_OBJECT
 public:
  explicit PID(float _kp, float _ki, float _kd, QObject *parent = nullptr);

  /**
   * @brief setPid 设置pid参数
   * @param p
   * @param i
   * @param d
   */
  void setPid(float p, float i, float d);

  /**
   * @brief control 控制函数
   * @return
   */
  float control(float _target, float _actual);

 signals:

 private:
  float kp = 10;       //比例系数
  float ki = 0.01;     //积分系数
  float kd = 0.01;     //微分系数
  float target = 0;    //目标值
  float actual = 0;    //实际值
  float e = 0;         //误差
  float e_pre = 0;     //上一次误差
  float integral = 0;  //积分项
};

#endif  // PID_H
