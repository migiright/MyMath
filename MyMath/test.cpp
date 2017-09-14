#include <iostream>
#include "MyMath.hpp"

using namespace std;

int main()
{
	Matrix<2, 3> m23{1.0, 2.0, 3.0, 4.0, 5.0, 6.0}; //2�s3��̍s��
	Matrix<3, 2> m32{1.0, 2.0, 3.0, 4.0, 5.0, 6.0}; //3�s2��̍s��
	m23 = m23 * 2; //�X�J���Ƃ̏�Z
	auto m22 = m23 * m32; //m23��m32�̐� 2�s2��̍s��
	cout << m22.toString() << endl; //�s������������ɕ\��

	Vector<3> v3{1.0, 2.0, 3.0}; //3�����̃x�N�g��
	v3 = v3 * 2; //�X�J���Ƃ̏�Z
	v3 = v3 / 2; //�X�J���ł̏��Z
	Vector<3> v32{2.0, 4.0, 6.0};
	v32 = v3 + v32; //�x�N�g�����m�̉��Z
	v32 = v3 - v32; //�x�N�g�����m�̌��Y
	cout << v32.toString() << endl;
	auto av1 = m23 * v3; //�s��Əc�x�N�g���̐� 2�����̃x�N�g��
	auto av2 = v3 * m32; //���x�N�g���ƍs��̐� 2�����̃x�N�g��
	cout << av1.toString() << endl;
	cout << av2.toString() << endl;

	return 0;
}