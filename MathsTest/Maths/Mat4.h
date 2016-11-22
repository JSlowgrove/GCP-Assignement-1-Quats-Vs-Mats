#pragma once

#include "Vec4.h"
#include "Vec3.h"
#include "Convert.h"

/**
@brief The namespace for all maths code.
*/
namespace Maths
{

	/**
	@brief Contains the Mat4 structure with functions and overloaded operators.
	*/
	struct Mat4
	{
		///Vec4 variables
		Vec4 row1, row2, row3, row4;

		/**
		@brief Constructs the Mat4 setting the values of the vec4's to 0,0,0,0.
		*/
		Mat4() : row1(), row2(), row3(), row4() {}

		/**
		@brief Constructs the Mat4 setting the values to the input vectors.
		@param row1 The first inputed vector.
		@param row2 The second inputed vector.
		@param row3 The third inputed vector.
		@param row4 The forth inputed vector.
		*/
		Mat4(Vec4 row1, Vec4 row2, Vec4 v3, Vec4 v4) : row1(row1), row2(row2), row3(row3), row4(row4) {}

		/**
		@brief Overloads the += operator.
		@param vecIn The input Mat4.
		@returns The new matrix.
		*/
		Mat4* operator += (Mat4 matIn)
		{
			row1.x += matIn.row1.x;
			row1.y += matIn.row1.y;
			row1.z += matIn.row1.z;
			row1.w += matIn.row1.w;
			row2.x += matIn.row2.x;
			row2.y += matIn.row2.y;
			row2.z += matIn.row2.z;
			row2.w += matIn.row2.w;
			row3.x += matIn.row3.x;
			row3.y += matIn.row3.y;
			row3.z += matIn.row3.z;
			row3.w += matIn.row3.w;
			row4.x += matIn.row4.x;
			row4.y += matIn.row4.y;
			row4.z += matIn.row4.z;
			row4.w += matIn.row4.w;
			return this;
		}

		/**
		@brief Overloads the -= operator.
		@param vecIn The input Mat4.
		@returns The new matrix.
		*/
		Mat4* operator -= (Mat4 matIn)
		{
			row1.x -= matIn.row1.x;
			row1.y -= matIn.row1.y;
			row1.z -= matIn.row1.z;
			row1.w -= matIn.row1.w;
			row2.x -= matIn.row2.x;
			row2.y -= matIn.row2.y;
			row2.z -= matIn.row2.z;
			row2.w -= matIn.row2.w;
			row3.x -= matIn.row3.x;
			row3.y -= matIn.row3.y;
			row3.z -= matIn.row3.z;
			row3.w -= matIn.row3.w;
			row4.x -= matIn.row4.x;
			row4.y -= matIn.row4.y;
			row4.z -= matIn.row4.z;
			row4.w -= matIn.row4.w;
			return this;
		}

		/**
		@brief Overloads the *= operator.
		@param vecIn The input Mat4.
		@returns The new matrix.
		*/
		Mat4* operator *= (Mat4 matIn)
		{
			row1.x *= matIn.row1.x;
			row1.y *= matIn.row2.x;
			row1.z *= matIn.row3.x;
			row1.w *= matIn.row4.x;
			row2.x *= matIn.row1.y;
			row2.y *= matIn.row2.y;
			row2.z *= matIn.row3.y;
			row2.w *= matIn.row4.y;
			row3.x *= matIn.row1.z;
			row3.y *= matIn.row2.z;
			row3.z *= matIn.row3.z;
			row3.w *= matIn.row4.z;
			row4.x *= matIn.row1.w;
			row4.y *= matIn.row2.w;
			row4.z *= matIn.row3.w;
			row4.w *= matIn.row4.w;
			return this;
		}

		/**
		@brief Sets the values of the matrix to that of a identity matrix
		*/
		void setAsIdentityMatrix()
		{
			row1.x = 1.0f; row1.y = 0.0f; row1.z = 0.0f; row1.w = 0.0f;
			row2.x = 0.0f; row2.y = 1.0f; row2.z = 0.0f; row2.w = 0.0f;
			row3.x = 0.0f; row3.y = 0.0f; row3.z = 1.0f; row3.w = 0.0f;
			row4.x = 0.0f; row4.y = 0.0f; row4.z = 0.0f; row4.w = 1.0f;
		}

		/**
		@brief Scales the matrix using the input vector
		@param scaleVector The vec3 to scale the matrix by.
		*/
		void scale(Vec3 scaleVector)
		{
			row1.x *= scaleVector.x;
			row2.y *= scaleVector.y;
			row3.z *= scaleVector.z;
		}

		/**
		@brief Translates the matrix using the input vector
		@param translationVector The vec3 to translate the matrix by.
		*/
		void translate(Vec3 translationVector)
		{
			row1.w += translationVector.x;
			row2.w += translationVector.y;
			row3.w += translationVector.z;
		}

		/**
		@brief Rotate the matrix using the input vector along the x axis
		@param rotateVector The vec3 to rotate the matrix by.
		*/
		void rotateAlongX(Vec3 rotateVector)
		{
			row2.y *= rotateVector.y;
			row2.z *= -rotateVector.z;
			row3.y *= rotateVector.y;
			row3.z *= rotateVector.z;
		}

		/**
		@brief Rotate the matrix using the input vector along the y axis
		@param rotateVector The vec3 to rotate the matrix by.
		*/
		void rotateAlongY(Vec3 rotateVector)
		{
			row1.x *= rotateVector.x; 
			row1.z *= rotateVector.z;
			row3.x *= -rotateVector.x; 
			row3.z *= rotateVector.z;
		}

		/**
		@brief Rotate the matrix using the input vector along the z axis
		@param rotateVector The vec3 to rotate the matrix by.
		*/
		void rotateAlongZ(Vec3 rotateVector)
		{
			row1.x *= rotateVector.x; 
			row1.y *= -rotateVector.y;
			row2.x *= rotateVector.x; 
			row2.y *= rotateVector.y;
		}

		/**
		@brief Rotate the matrix using the angle of rotation in degrees along the x axis
		@param angle The angle to rotate the matrix by.
		*/
		void rotateAlongXDeg(float angle)
		{
			rotateAlongXRad(Convert::convertDegreeToRadian(angle));
		}

		/**
		@brief Rotate the matrix using the angle of rotation in degrees along the y axis
		@param angle The angle to rotate the matrix by.
		*/
		void rotateAlongYDeg(float angle)
		{
			rotateAlongYRad(Convert::convertDegreeToRadian(angle));
		}

		/**
		@brief Rotate the matrix using the angle of rotation in degrees along the z axis
		@param angle The angle to rotate the matrix by.
		*/
		void rotateAlongZDeg(float angle)
		{
			rotateAlongZRad(Convert::convertDegreeToRadian(angle));
		}

		/**
		@brief Rotate the matrix using the angle of rotation in radians along the x axis
		@param angle The angle to rotate the matrix by.
		*/
		void rotateAlongXRad(float angle)
		{
			row2.y += cos(angle);
			row2.z += -sin(angle);
			row3.y += sin(angle);
			row3.z += cos(angle);
		}

		/**
		@brief Rotate the matrix using the angle of rotation in radians along the y axis
		@param angle The angle to rotate the matrix by.
		*/
		void rotateAlongYRad(float angle)
		{
			row1.x += cos(angle);
			row1.z += sin(angle);
			row3.x += -sin(angle);
			row3.z += cos(angle);
		}

		/**
		@brief Rotate the matrix using the angle of rotation in radians along the z axis
		@param angle The angle to rotate the matrix by.
		*/
		void rotateAlongZRad(float angle)
		{
			row1.x += cos(angle);
			row1.y += -sin(angle);
			row2.x += sin(angle);
			row2.y += cos(angle);
		}

		/**
		@brief Set the rotation of the matrix using the angle of rotation in degrees along the x axis
		@param angle The angle of rotation.
		*/
		void setRotationAlongXDeg(float angle)
		{
			setRotationAlongXRad(Convert::convertDegreeToRadian(angle));
		}

		/**
		@brief Set the rotation of the matrix using the angle of rotation in degrees along the y axis
		@param angle The angle of rotation.
		*/
		void setRotationAlongYDeg(float angle)
		{
			setRotationAlongYRad(Convert::convertDegreeToRadian(angle));
		}

		/**
		@brief Set the rotation of the matrix using the angle of rotation in degrees along the z axis
		@param angle The angle of rotation.
		*/
		void setRotationAlongZDeg(float angle)
		{
			setRotationAlongZRad(Convert::convertDegreeToRadian(angle));
		}

		/**
		@brief Set the rotation of the matrix using the angle of rotation in radians along the x axis
		@param angle The angle of rotation.
		*/
		void setRotationAlongXRad(float angle)
		{
			row2.y = cos(angle);
			row2.z = -sin(angle);
			row3.y = sin(angle);
			row3.z = cos(angle);
		}

		/**
		@brief Set the rotation of the matrix using the angle of rotation in radians along the y axis
		@param angle The angle of rotation.
		*/
		void setRotationAlongYRad(float angle)
		{
			row1.x = cos(angle);
			row1.z = sin(angle);
			row3.x = -sin(angle);
			row3.z = cos(angle);
		}

		/**
		@brief Set the rotation of the matrix using the angle of rotation in radians along the z axis
		@param angle The angle of rotation.
		*/
		void setRotationAlongZRad(float angle)
		{
			row1.x = cos(angle);
			row1.y = -sin(angle);
			row2.x = sin(angle);
			row2.y = cos(angle);
		}
	};

	/**
	@brief Overloads the + operator allowing a Mat4 to be added to a scalar.
	@param matInA The input Mat4.
	@param scalar The scalar to add.
	@returns The new Mat4.
	*/
	inline Mat4 operator + (Mat4 matInA, float scalar)
	{
		Mat4 matOut;
		matOut.row1.x = matInA.row1.x + scalar;
		matOut.row1.y = matInA.row1.y + scalar;
		matOut.row1.z = matInA.row1.z + scalar;
		matOut.row1.w = matInA.row1.w + scalar;
		matOut.row2.x = matInA.row2.x + scalar;
		matOut.row2.y = matInA.row2.y + scalar;
		matOut.row2.z = matInA.row2.z + scalar;
		matOut.row2.w = matInA.row2.w + scalar;
		matOut.row3.x = matInA.row3.x + scalar;
		matOut.row3.y = matInA.row3.y + scalar;
		matOut.row3.z = matInA.row3.z + scalar;
		matOut.row3.w = matInA.row3.w + scalar;
		matOut.row4.x = matInA.row4.x + scalar;
		matOut.row4.y = matInA.row4.y + scalar;
		matOut.row4.z = matInA.row4.z + scalar;
		matOut.row4.w = matInA.row4.w + scalar;
		return matOut;
	}

	/**
	@brief Overloads the + operator allowing a Mat4 to be added to a scalar.
	@param matInA An input Mat4.
	@param matInA An input Mat4.
	@returns The new Mat4.
	*/
	inline Mat4 operator + (Mat4 matInA, Mat4 matInB)
	{
		Mat4 matOut;
		matOut.row1.x = matInA.row1.x + matInB.row1.x;
		matOut.row1.y = matInA.row1.y + matInB.row1.y;
		matOut.row1.z = matInA.row1.z + matInB.row1.z;
		matOut.row1.w = matInA.row1.w + matInB.row1.w;
		matOut.row2.x = matInA.row2.x + matInB.row2.x;
		matOut.row2.y = matInA.row2.y + matInB.row2.y;
		matOut.row2.z = matInA.row2.z + matInB.row2.z;
		matOut.row2.w = matInA.row2.w + matInB.row2.w;
		matOut.row3.x = matInA.row3.x + matInB.row3.x;
		matOut.row3.y = matInA.row3.y + matInB.row3.y;
		matOut.row3.z = matInA.row3.z + matInB.row3.z;
		matOut.row3.w = matInA.row3.w + matInB.row3.w;
		matOut.row4.x = matInA.row4.x + matInB.row4.x;
		matOut.row4.y = matInA.row4.y + matInB.row4.y;
		matOut.row4.z = matInA.row4.z + matInB.row4.z;
		matOut.row4.w = matInA.row4.w + matInB.row4.w;
		return matOut;
	}

	/**
	@brief Overloads the - operator allowing a Mat4 to be added to a scalar.
	@param matInA The input Mat4.
	@param scalar The scalar to add.
	@returns The new Mat4.
	*/
	inline Mat4 operator - (Mat4 matInA, float scalar)
	{
		Mat4 matOut;
		matOut.row1.x = matInA.row1.x - scalar;
		matOut.row1.y = matInA.row1.y - scalar;
		matOut.row1.z = matInA.row1.z - scalar;
		matOut.row1.w = matInA.row1.w - scalar;
		matOut.row2.x = matInA.row2.x - scalar;
		matOut.row2.y = matInA.row2.y - scalar;
		matOut.row2.z = matInA.row2.z - scalar;
		matOut.row2.w = matInA.row2.w - scalar;
		matOut.row3.x = matInA.row3.x - scalar;
		matOut.row3.y = matInA.row3.y - scalar;
		matOut.row3.z = matInA.row3.z - scalar;
		matOut.row3.w = matInA.row3.w - scalar;
		matOut.row4.x = matInA.row4.x - scalar;
		matOut.row4.y = matInA.row4.y - scalar;
		matOut.row4.z = matInA.row4.z - scalar;
		matOut.row4.w = matInA.row4.w - scalar;
		return matOut;
	}

	/**
	@brief Overloads the - operator allowing a Mat4 to be subtracted from a scalar.
	@param matInA An input Mat4.
	@param matInA An input Mat4.
	@returns The new Mat4.
	*/
	inline Mat4 operator - (Mat4 matInA, Mat4 matInB)
	{
		Mat4 matOut;
		matOut.row1.x = matInA.row1.x - matInB.row1.x;
		matOut.row1.y = matInA.row1.y - matInB.row1.y;
		matOut.row1.z = matInA.row1.z - matInB.row1.z;
		matOut.row1.w = matInA.row1.w - matInB.row1.w;
		matOut.row2.x = matInA.row2.x - matInB.row2.x;
		matOut.row2.y = matInA.row2.y - matInB.row2.y;
		matOut.row2.z = matInA.row2.z - matInB.row2.z;
		matOut.row2.w = matInA.row2.w - matInB.row2.w;
		matOut.row3.x = matInA.row3.x - matInB.row3.x;
		matOut.row3.y = matInA.row3.y - matInB.row3.y;
		matOut.row3.z = matInA.row3.z - matInB.row3.z;
		matOut.row3.w = matInA.row3.w - matInB.row3.w;
		matOut.row4.x = matInA.row4.x - matInB.row4.x;
		matOut.row4.y = matInA.row4.y - matInB.row4.y;
		matOut.row4.z = matInA.row4.z - matInB.row4.z;
		matOut.row4.w = matInA.row4.w - matInB.row4.w;
		return matOut;
	}

	/**
	@brief Overloads the * operator allowing a Mat4 to be multiplied to a scalar.
	@param matInA The input Mat4.
	@param scalar The scalar to add.
	@returns The new Mat4.
	*/
	inline Mat4 operator * (Mat4 matInA, float scalar)
	{
		Mat4 matOut;
		matOut.row1.x = matInA.row1.x * scalar;
		matOut.row1.y = matInA.row1.y * scalar;
		matOut.row1.z = matInA.row1.z * scalar;
		matOut.row1.w = matInA.row1.w * scalar;
		matOut.row2.x = matInA.row2.x * scalar;
		matOut.row2.y = matInA.row2.y * scalar;
		matOut.row2.z = matInA.row2.z * scalar;
		matOut.row2.w = matInA.row2.w * scalar;
		matOut.row3.x = matInA.row3.x * scalar;
		matOut.row3.y = matInA.row3.y * scalar;
		matOut.row3.z = matInA.row3.z * scalar;
		matOut.row3.w = matInA.row3.w * scalar;
		matOut.row4.x = matInA.row4.x * scalar;
		matOut.row4.y = matInA.row4.y * scalar;
		matOut.row4.z = matInA.row4.z * scalar;
		matOut.row4.w = matInA.row4.w * scalar;
		return matOut;
	}

	/**
	@brief Overloads the * operator allowing a Mat4 to be multiplied with another Mat4.
	@param matInA An input Mat4.
	@param matInB An input Mat4.
	@returns The new Mat4.
	*/
	inline Mat4 operator * (Mat4 matInA, Mat4 matInB)
	{
		Mat4 matOut;
		matOut.row1.x = matInA.row1.x * matInA.row1.x;
		matOut.row1.y = matInA.row1.y * matInA.row2.x;
		matOut.row1.z = matInA.row1.z * matInA.row3.x;
		matOut.row1.w = matInA.row1.w * matInA.row4.x;
		matOut.row2.x = matInA.row2.x * matInA.row1.y;
		matOut.row2.y = matInA.row2.y * matInA.row2.y;
		matOut.row2.z = matInA.row2.z * matInA.row3.y;
		matOut.row2.w = matInA.row2.w * matInA.row4.y;
		matOut.row3.x = matInA.row3.x * matInA.row1.z;
		matOut.row3.y = matInA.row3.y * matInA.row2.z;
		matOut.row3.z = matInA.row3.z * matInA.row3.z;
		matOut.row3.w = matInA.row3.w * matInA.row4.z;
		matOut.row4.x = matInA.row4.x * matInA.row1.w;
		matOut.row4.y = matInA.row4.y * matInA.row2.w;
		matOut.row4.z = matInA.row4.z * matInA.row3.w;
		matOut.row4.w = matInA.row4.w * matInA.row4.w;
		return matOut;
	}

}// End of Maths namespace