#ifndef __PARA_RENDER_SCENE_HPP__
#define __PARA_RENDER_SCENE_HPP__

#pragma once

#include <vector>
typedef unsigned int ElementID;
namespace Para
{
	class RenderElement;

	class RenderScene
	{
	public:
		RenderScene();
		~RenderScene();

		void render();
		void addElement(RenderElement* element);
		void removeElement(ElementID id);

		/** Usuwa wszystkie obiekty które znajduj¹ siê na scenie*/
		void clear();
	private:
		//TODO zrobiæ coœ do przechowywania kamery
		//TODO zrobiæ coœ do przechowywania œwiat³a
		std::vector<RenderElement*> m_elements;
	};
}


#endif //__PARA_RENDER_SCENE_HPP__