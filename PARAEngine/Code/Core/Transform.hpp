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

	/** Klasa odpowiedzialana za transformacjê obiektu. Klasa przechowuje informacje 
	o pozycji, rotacji i skali obiektu. Przechowuje tak¿e informacjê o macierzy transformacji
	która powstaje w wyniku odpowiednich przekszta³ceñ pozycji, rotacji i skali. Macierz transformacji
	bêdzie u¿ywana do okreslenia po³o¿eñ wierzcho³ków*/
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

		/** Metoda ustawiaj¹ca pozycjê. Po ustawieniu pozycji zostaje zanzaczona zmiana transformacji. 
		Macierz transformacji zostanie obliczona przy skorzystaniu z metody getTransformMatrix*/
		void setPosition(const Vec3& position) { m_position = position; m_transform_change = true; }
		void setRotation(const Vec3& rotation) { m_rotation = rotation; m_transform_change = true; }
		void setScale(const Vec3& scale) { m_scale = scale; m_transform_change = true; }

		/** Zwraca macierz transformacji. Je¿eli m_transform_change jest true, macierz zostaje ponowanie obliczona,
		a nastepnie zwrócona. */
		Mat4& getTransformMatrix();
	private:
		/// Pozycja 
		Vec3 m_position;
		/// Obrót
		Vec3 m_rotation; //TODO mo¿na przedstawiæ obrót jako kwaternion
		/// Skala
		Vec3 m_scale; //TODO mo¿na przedstawiæ skalê jako pojedyñczy float
		/// Macierz zawieraj¹ca obliczon¹ transformacjê
		Mat4 m_transform_matrix;
		/// Zmienna okreœlaj¹ca, czy któraœ z wartoœci (pozycja, obrót lub skala) uleg³y zmianie. 
		///Korzystamy z tej zmiennej zamiast aktualizowaæ macierz transformacji po zmianie parametrów, ponmiewa¿w jednej klatce 
		/// mo¿e nast¹piæ kilka zmian parametrów
		bool m_transform_change;
	private:
		/** Oblicza macierz transformacji na podstawie pozycji, rotacji i skali*/
		void updateTransform();
	};
}


#endif //__PARA_TRANSFORM_HPP__