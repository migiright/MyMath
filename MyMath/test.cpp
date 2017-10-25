#include <iostream>
#include "MyMath.hpp"

using namespace std;
using namespace MyMath;

int main()
{
	Matrix<2, 3> m23{1.0, 2.0, 3.0, 4.0, 5.0, 6.0}, m232{2.0, 3.0, 4.0, 5.0, 6.0, 7.0}; //2行3列の行列
	Matrix<3, 2> m32{1.0, 2.0, 3.0, 4.0, 5.0, 6.0}; //3行2列の行列
	m23 = m23 * 2; //スカラとの乗算
	m23 = m23 + m232; //行列同士の加算
	m23 = m23 - m232; //行列同士の減算
	m23 = -m23; //反数を取る
	auto m22 = m23 * m32; //m23とm32の積 2行2列の行列
	cout << m22.toString() << endl; //行列をいい感じに表示

	Vector<3> v3{1.0, 2.0, 3.0}; //3次元のベクトル
	v3 = v3 * 2; //スカラとの乗算
	v3 = v3 / 2; //スカラでの除算
	v3 = -v3; //反数
	Vector<3> v32{2.0, 4.0, 6.0};
	v32 = v3 + v32; //ベクトル同士の加算
	v32 = v3 - v32; //ベクトル同士の減産
	cout << v32.toString() << endl;
	auto av1 = m23 * v3; //行列と縦ベクトルの積 2次元のベクトル
	auto av2 = v3 * m32; //横ベクトルと行列の積 2次元のベクトル
	cout << av1.toString() << endl;
	cout << av2.toString() << endl;
	cout << dot(v3, v32) << endl; //ベクトル同士の内積
	cout << norm(v3) << endl; //ノルム

	auto v22 = pickColumn(m23, 0); //列を抜き出す
	cout << v22.toString() << endl;
	auto v33 = pickRow(m23, 1); //行を抜き出す
	cout << v33.toString() << endl;

	//ベクトル値関数のヤコビアン
	{
		auto f = [](Vector<2> x) { //ベクトル値関数
			return Vector<2>{ x[0]*x[1]*x[1], sin(x[0]) * cos(x[1]) };
		};
		auto df = [](Vector<2> x) { //ヤコビアン(比較用の解析解)
			return Matrix<2, 2>{ x[1]*x[1], 2*x[0]*x[1], cos(x[0]) * cos(x[1]), -sin(x[0]) * sin(x[1])};
		};
		Vector<2> x{2.0, 3.0};
		Matrix<2, 2> d1 = jacobianMatrix(f, x);
		printf("%.20e, %.20e, %.20e, %.20e\n", d1(0, 0), d1(0, 1), d1(1, 0), d1(1, 1));
		Matrix<2, 2> d2 = df(x);
		printf("%.20e, %.20e, %.20e, %.20e\n", d2(0, 0), d2(0, 1), d2(1, 0), d2(1, 1));
	}

	//スカラー値関数のヤコビアン
	{
		auto f = [](Vector<2> x) { //スカラー値関数
			return x[0] * sin(x[1]);
		};
		auto df = [](Vector<2> x) { //ヤコビアン(比較用の解析解)
			return Vector<2>{ sin(x[1]), x[0] * cos(x[1])};
		};
		Vector<2> x{2.0, 3.0};
		Vector<2> d1 = jacobianVector(f, x);
		printf("%.20e, %.20e\n", d1[0], d1[1]);
		Vector<2> d2 = df(x);
		printf("%.20e, %.20e\n", d2[0], d2[1]);
	}

	//Lie微分
	{
		auto f = [](Vector<2> x){ //ベクトル値関数
			return Vector<2>{x[0]*x[1], x[0]+x[1]};
		};
		auto v = [](Vector<2> x){ //スカラー値関数
			return x[0]*x[0]*x[1];
		};
		auto dv = [](Vector<2> x) { //ヤコビアン(比較用の解析解)
			return Vector<2>{2*x[0]*x[1], x[0]*x[0]};
		};
		auto lfv = [dv, f](Vector<2> x){ //Lie微分(比較用の解析解)
			return dot(dv(x), f(x));
		};
		Vector<2> x{2.0, 3.0};
		auto l1 = lie(f, v, x), l2 = lfv(x);
		printf("%.20e, %.20e\n", l1, l2);
	}

	return 0;
}
