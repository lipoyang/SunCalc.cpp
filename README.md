# 太陽の位置を計算するC++クラス

※ これは学習用のサンプルコードです。精密な計算ではありません。

## 入力
### UTC日時
- year (1900～2199)
- month (1～12)
- day (1～31)
- hour (0～23)
- min (0～59)
- sec (0～59)

### 観測地点の位置
- longitude [deg] (-180～+180) : 経度
- latitude [deg] (-90～+90) : 緯度

## 出力
位置も時刻も単位はラジアンに統一

### 太陽の位置
- L [rad] : 平均黄経
- g [rad] : 平均近点角
- lambda [rad] : 視黄経
- alpha [rad] : 赤経
- delta [rad] : 赤緯
- eqation [rad] : 均時差

### 時刻
- t_UTC [rad] : 世界協定時
- t_LMT [rad] : 地方平均時
- t_LTST [rad] : 地方視太陽時
- t_LST [rad] : 地方恒星時

