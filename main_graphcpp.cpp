#include "human.h"


int main() {
	setlocale(LC_ALL, "");

	Human h;

	h.add_name("����");
	h.add_name("����");
	h.add_name("����");
	h.add_name("����");
	h.add_name("�����");
	h.add_name("����");
	h.add_name("����");
	h.add_name("�����");
	h.add_name("����");
	h.add_name("����");

	h.add_hand(1, 2);
	h.add_hand(1, 5);
	h.add_hand(2, 4);
	h.add_hand(3, 5);
	h.add_hand(3, 6);
	h.add_hand(4, 7);
	h.add_hand(7, 8);
	h.add_hand(7, 9);
	h.add_hand(6, 9);
	h.add_hand(6, 10);

	h.show();

	h.findPathCount();


}