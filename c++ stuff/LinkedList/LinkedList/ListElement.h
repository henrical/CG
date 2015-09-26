#ifndef _LIST_ELEMENT_H_
#define _LIST_ELEMENT_H_

#include <iostream>
#include <string>


template <typename T>
class ListElement{

	private:
		ListElement* next;
		T content;

	public:
		ListElement() {
			next = nullptr;
			this.content = T();
		}

		ListElement(T content){
			next = nullptr;
			this->content = content;
		}

		/*std::string toString(){
			return content->toString<T>();
		}*/

		int setNext(ListElement *ele){
			if (ele == nullptr) return -1;

			this->next = ele;
			return 1;
		}
};

#endif