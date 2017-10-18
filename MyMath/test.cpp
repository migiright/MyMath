#include <iostream>
#include "MyMath.hpp"

using namespace std;
using namespace MyMath;

int main()
{
	Matrix<2, 3> m23{1.0, 2.0, 3.0, 4.0, 5.0, 6.0}; //2行3列の行列
	Matrix<3, 2> m32{1.0, 2.0, 3.0, 4.0, 5.0, 6.0}; //3行2列の行列
	m23 = m23 * 2; //スカラとの乗算
	auto m22 = m23 * m32; //m23とm32の積 2行2列の行列
	cout << m22.toString() << endl; //行列をいい感じに表示

	Vector<3> v3{1.0, 2.0, 3.0}; //3次元のベクトル
	v3 = v3 * 2; //スカラとの乗算
	v3 = v3 / 2; //スカラでの除算
	Vector<3> v32{2.0, 4.0, 6.0};
	v32 = v3 + v32; //ベクトル同士の加算
	v32 = v3 - v32; //ベクトル同士の減産
	cout << v32.toString() << endl;
	auto av1 = m23 * v3; //行列と縦ベクトルの積 2次元のベクトル
	auto av2 = v3 * m32; //横ベクトルと行列の積 2次元のベクトル
	cout << av1.toString() << endl;
	cout << av2.toString() << endl;
	cout << dot(v3, v32) << endl; //ベクトル同士の内積

	return 0;
}
