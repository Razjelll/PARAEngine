#ifndef __PARA_TRANSFORM_HPP__
#define __PARA_TRANSFORM_HPP__
#pragma once

#include "../../Libraries/glm/glm.hpp"

typedef glm::vec3 Vec3;
typedef glm::vec2 Vec2;
typedef glm::mat4 Mat4;

namespace Para 
{

	enum class Axis
	{
		X,
		Y,
		Z
	};

	/** Klasa odpowiedzialana za transformacj� obiektu. Klasa przechowuje informacje 
	o pozycji, rotacji i skali obiektu. Przechowuje tak�e informacj� o macierzy transformacji
	kt�ra powstaje w wyniku odpowiednich przekszta�ce� pozycji, rotacji i skali. Macierz transformacji
	b�dzie u�ywana do okreslenia po�o�e� wierzcho�k�w*/
	class Transform
	{
	public:
		Transform();
		~Transform();

		void translate(const Vec3& translation);
		void translate(Axis axis,const float translation);
		void rotate(const Vec3& rotation);
		void rotate(Axis axis,const float rotation);
		void scale(const Vec3& scale);
		void scale(const float scale);
		void scale(Axis axis,const float scale);


		Vec3& getPosition() { return m_position; }
		Vec3& getRotation() { return m_rotation; }
		Vec3& getScale() { return m_scale; }

		/** Metoda ustawiaj�ca pozycj�. Po ustawieniu pozycji zostaje zanzaczona zmiana transformacji. 
		Macierz transformacji zostanie obliczona przy skorzystaniu z metody getTransformMatrix*/
		void setPosition(const Vec3& position) { m_position = position; m_transform_change = true; }
		void setRotation(const Vec3& rotation) { m_rotation = rotation; m_transform_change = true; }
		void setScale(const Vec3& scale) { m_scale = scale; m_transform_change = true; }

		/** Zwraca macierz transformacji. Je�eli m_transform_change jest true, macierz zostaje ponowanie obliczona,
		a nastepnie zwr�cona. */
		Mat4& getTransformMatrix();
	private:
		/// Pozycja 
		Vec3 m_position;
		/// Obr�t
		Vec3 m_rotation; //TODO mo�na przedstawi� obr�t jako kwaternion
		/// Skala
		Vec3 m_scale; //TODO mo�na przedstawi� skal� jako pojedy�czy float
		/// Macierz zawieraj�ca obliczon� transformacj�
		Mat4 m_transform_matrix;
		/// Zmienna okre�laj�ca, czy kt�ra� z warto�ci (pozycja, obr�t lub skala) uleg�y zmianie. 
		///Korzystamy z tej zmiennej zamiast aktualizowa� macierz transformacji po zmianie parametr�w, ponmiewa�w jednej klatce 
		/// mo�e nast�pi� kilka zmian parametr�w
		bool m_transform_change;
	private:
		/** Oblicza macierz transformacji na podstawie pozycji, rotacji i skali*/
		void updateTransform();
	};
}


#endif //__PARA_TRANSFORM_HPP__