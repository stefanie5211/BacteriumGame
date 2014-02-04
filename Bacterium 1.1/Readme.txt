2010.10.11

修改内容：
1.EventManager中选兵容器由vector 改为multimap；
2.EventManager中添加方法SelecteUnitType， 括选
  兵种后，在GUI界面单击某种兵按钮，对该兵种进行
  选择；

3.Constant中UnitType枚举值修改，将BCTERIUM属性
  修改为STARBACTERIUM, BALLBACTERIUM；

4.Unit 中的UnitType 属性由bacterium初始化改为
  Bacterium子类（兵种类，如BallBacterium）初始
  化为不同类型兵种；