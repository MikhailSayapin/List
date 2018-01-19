#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <limits.h> 

using namespace std;
setlocale(LC_ALL, "Russian");

struct List
{
   int a;
   List *next
}

void choice()
{
   cout << "1. Печать списка;" << endl;
   cout << "2. Добавление элементов в список;" << endl;
   cout << "3. Удаление элемента;" << endl;
   cout << "4. Поиск позиций элементов;" << endl;
   cout << "5. Замена элемента н другой;" << endl;
   cout << "6. Сортировка элементов списка;" << endl;
   cout << "7. Завершение работы\n" << endl;
}


int main (int argc, char* argv[])
{
   int *elements = new int [argc - 1];
   
   for (int i = 1; i < argc; i++)
   {
      elements[i] = atoi(argv[i]);
   }
   
   List *first = nullptr
   
   if (argc == 1)
   {
      List *first = nullptr;
   }
   
   else 
   {
     (*first) = new List;
     (*first) -> a = *(elements + 1);
     (*first) -> next = nullptr;
     List *curr = *first;
     
     for (int i = 2; i < argc; i++)
     {
        curr -> next = new List;
        curr = curr -> next;
        curr -> a = *(elements + i);
        curr -> next = nullptr;
     }
     
   }
   
   
   int ch;
   while(true)
   {
      cout << "1. Печать списка;" << endl;
      cout << "2. Добавление элементов в список;" << endl;
      cout << "3. Удаление элемента;" << endl;
      cout << "4. Поиск позиций элементов;" << endl;
      cout << "5. Замена элемента н другой;" << endl;
      cout << "6. Сортировка элементов списка;" << endl;
      cout << "7. Завершение работы\n" << endl;
      
      cin >> ch;
      switch(ch)
      {
         case 7:
         {
            string z;
            cout << "Вы точно хотите выйти?";
            cin >> z;
            if ((z == "y") || (z == "Y") || (z == "yes") || (z == "Yes") || (z == "YES"))
            {
               cout << "До свидания";
               return 0;
            }
         }
         
         case 1:
         {
            List *print = first;
            if (print == nullptr)
            {
               cout << "Список пуст\n" << endl;
            }
            
            else
            {
               do
               {
                  cout << print -> a;
                  if (print -> next)
                  {
                     cout << " -> ";
                  }
                  print = print -> next;
               }
               while(print);
               cout << "\n";
            }
            break;
         }
         
         
         case 2:
         {
            cout << "Количество элементов, которое необходимо добавить:\t";
            int razm;
            cin >> razm;
            cout << "Введите элементы:\t";
            int *arr = new int [razm];
            
            for (int i = 0; i < razm; i++)
            {
               cin >> arr[i];
            }
            
            List *p = *first;
	         List *p1 = p->next;
	         
	         while (p1)
	         {
	            p = p1;
	            p1 = p1 -> next;
	         }
	         
	         List *n = p;
	         
	         for (int i = 0; i < razm; i++)
	         {
	            n -> next = new List;
	            n = n -> next;
	            n -> a = *(arr + i);
	            n -> next = nullptr;
	         }
	         
	         delete [] arr;
	         break;
         }
         
         
         case 3:
         {
            if ((*first) == nullptr)
            {
               cout << "Список пуст \n" << endl;
            }
            
            else
            {
               int d;
               cout << "Введите элемент для удаления: \t";
               cin >> d;
               List *p = *first;
               if (p -> a == d)
               {
                  *first = p -> next;
                  delete p;
               }
               
               List *p1 = p -> next;
               
               while (p1)
               {
                  if (p1 -> a == b)
                  {
                     p -> next = p1 -> next;
                     delete p1;
                  }
               }
               
               p = p1;
               p1 = p1 -> next;
            }
            break;
         }
         
         
         case 4:
         {
            List *curr = *first;
            int el;
            int razm;
            bool logic;
            el = 0;
            razm = 0;
            logic = false;
            cout << "Введите элемент для поиска:\t";
            cin >> el;
            
            while (curr != nullptr)
            {
               if (curr -> a == el)
               {
                  cout << "Позиция № " << razm;
                  logic = true;
               }
               
               razm++;
               curr = curr -> next;
            }
            
            if (logic == false)
            {
               cout << "Элемент не найден\n" << endl;
            }
            break;
         }
         
         
         case 5:
         {
            int pozition;
            int el;
            int i;
            position = 0;
            i = 0;
         
            cout << "Позиция :\t";
            cin >> position;
            cout << "Новый элемент:\t";
            cin >> el;
            
            bool logic_el;
            logic_el = false;
            List *curr = (*first);
            
            while (curr != nullptr)
            {
               if (i ==position)
               {
                  curr -> a = el;
                  logic_el = true;
               }
               
               curr = curr -> next;
               i++;
            }
            
            if (logic_el == false)
            {
               cout << "Неправильный ввод\n" << endl;
            }
            break;
         }
         
         
         case 6:
         {
            	for (List *curr = (*first); curr != nullptr; curr = curr->next)
            	{
            	   for (List *curr1 = (*first); curr1 != nullptr; curr1 = curr1->next)
            	   {
            	      if ((curr->a) < (curr1->a))
            	      swap(curr->a,curr1->a);
            	   }
            	}
            	break;
         }
        
         
         default:
         {
            cout << "Неизвестная ошибка\n" << endl;
         }
      }
   }
   return 0;
}
