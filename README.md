# 2016年度コンピューターグラフィクス論提出Repository
## About this repo

### Name
茂山丈太郎 03-143003
工学部機械情報工学科4年
email:jotaro@cyber.t.u-tokyo.ac.jp

コンピューターグラフィクス論の課題１，２をopenFrameworks形式で提出いたします。
各リポジトリの/src/ofApp.cppが実装内容、/bin/xxx.appが実行可能アプリです。
Mac環境で実行可能と思われます．

## 1.Besier Curve
n次のベジエ曲線描画アプリです。
ベルンシュタイン関数の方法で解いたものです。
クリックで制御点を追加。
shift・altキーで、制御点のドラッグ、削除、GUI上に分割数のスライダ。

## 2.Inverse Kinematics
Cyclic decent法による実装です。
### 調査
Cyclic decent法だけでは，物体の質量特性や衝突，拘束条件やトルク特性などの考慮はなされてないため，初期位置に対するエンドエフェクタの目的位置によっては不安定な動きをすることがある．このような運動を実際の物体の特性を考慮したものに近づけるために，逆動力学(Inverse Dynamics)の知識が用いられる．