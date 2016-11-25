#include "Mat4.h"

namespace Maths
{

	void Mat4::scale(Mat4 &matrix, float sv) //uses row1x, row2y & row3z
	{
		//make a temporary identity matrix
		Mat4 tm;
		tm.setAsIdentityMatrix();

		tm.m[0] = sv;			/*y					  z					  w*/
		/*x*/				tm.m[5] = sv;			/*z					  w*/
		/*x					y*/						tm.m[10] = sv;		/*w*/
		/*x					y						z					  w*/

		//multiply the current matrix with the temporary matrix
		matrix = matrix * tm;
	}

	void Mat4::translate(Mat4 &matrix, Vec3 tv) //uses row1w, row2w & row3w
	{
		//make a temporary identity matrix
		Mat4 tm;
		tm.setAsIdentityMatrix();

		/*x		y		z*/		tm.m[3] = tv.x;
		/*x		y		z*/		tm.m[7] = tv.y;
		/*x		y		z*/		tm.m[11] = tv.z;
		/*x		y		z		w*/

		//multiply the current matrix with the temporary matrix
		matrix = matrix * tm;
	}

	void Mat4::rotateAlongX(Mat4 &matrix, float angle, angleType format) //uses row2y, row2z, row3y & row3z
	{
		//make a temporary identity matrix
		Mat4 tm;
		tm.setAsIdentityMatrix();

		//make sure the format of the angle is radians 
		if (format == degree)
		{
			angle = Convert::convertDegreeToRadian(angle);
		}

		/*x		y								z									  w*/
		/*x*/	tm.m[5] = float(cos(angle));	tm.m[6] = float(sin(angle));		/*w*/
		/*x*/	tm.m[9] = float(-sin(angle));	tm.m[10] = float(cos(angle));		/*w*/
		/*x		y								z									  w*/

		//multiply the current matrix with the temporary matrix
		matrix = matrix * tm;
	}

	void Mat4::rotateAlongY(Mat4 &matrix, float angle, angleType format) //uses row1x, row1z, row3x & row3z
	{
		//make a temporary identity matrix
		Mat4 tm;
		tm.setAsIdentityMatrix();

		//make sure the format of the angle is radians 
		if (format == degree)
		{
			angle = Convert::convertDegreeToRadian(angle);
		}

		tm.m[0] = float(cos(angle));	/*y*/		tm.m[2] = float(sin(angle));	/*w*/
		/*x								  y			z								  w*/
		tm.m[8] = float(-sin(angle));	/*y*/		tm.m[10] = float(cos(angle));	/*w*/
		/*x								  y			z								  w*/

		//multiply the current matrix with the temporary matrix
		matrix = matrix * tm;
	}

	void Mat4::rotateAlongZ(Mat4 &matrix, float angle, angleType format) //uses row1x, row1y, row2x & row2y
	{
		//make a temporary identity matrix
		Mat4 tm;
		tm.setAsIdentityMatrix();

		//make sure the format of the angle is radians 
		if (format == degree)
		{
			angle = Convert::convertDegreeToRadian(angle);
		}

		tm.m[0] = float(cos(angle));	tm.m[1] = float(sin(angle));	/*z			w*/
		tm.m[4] = float(-sin(angle));	tm.m[5] = float(cos(angle));	/*z			w*/
		/*x								y								  z			w*/
		/*x								y								  z			w*/

		//multiply the current matrix with the temporary matrix
		matrix = matrix * tm;
	}

}//End of Maths namespace