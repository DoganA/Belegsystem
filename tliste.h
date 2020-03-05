#ifndef TLISTE_H
#define TLISTE_H

#include <cstddef>     // für NULL
#include <cassert>     // für assert

template<class T>
class TListe
{
   private:
      struct Listenelement
      {
         T Daten;
         Listenelement *Next, *Prev;
         Listenelement(): Next(NULL), Prev(NULL) { }
      };

      Listenelement *Ende, *Anfang;
      int Anzahl;

   public:
      TListe();                // Konstruktor
      TListe(const TListe&);    // Kopierkonstruktor
      virtual ~TListe();       // Destruktor

      TListe& operator=(const TListe&);

      void clear()
      {
         while (!empty())
            pop_front();
      }
      bool empty() const { return Anzahl == 0; }
      int size()   const { return Anzahl;      }

      // am Anfang bzw. Ende einfügen
      void push_front(const T&);
      void push_back(const T&);

      // am Anfang bzw. Ende entnehmen
      void pop_front();
      void pop_back();

      // am Anfang bzw. Ende lesen
      T& front();
      const T& front() const;
      T& back();
      const T& back() const;

      // ========================================
      // Jetzt kommt die geschachtelte
      // Klasse für den Iterator:
      class Iterator
      {
         private:
            Listenelement* aktuell; // Zeiger auf
                             // aktuelles Element
         public:
            friend class TListe<T>; // wg. erase-Zugriff auf aktuell
            Iterator(Listenelement* Init = NULL): aktuell(Init) { }

            Iterator(const TListe& L)   {  *this = L.begin();      }

            const T& operator*() const {  return aktuell->Daten;  }

            T& operator*()             {  return aktuell->Daten;  }

            Iterator& operator++() // prefix
            {
               if (aktuell)
                  aktuell = aktuell->Next;
               return *this;
            }

            TListe::Iterator operator++(int prm1) // postfix
            {
               Iterator temp = *this;
               ++*this;
               return temp;
            }

            bool operator==(const Iterator& x) const
            {  return aktuell == x.aktuell; }

            bool operator!=(const Iterator& x) const
            {  return aktuell != x.aktuell; }

      }; // Iterator
      // Hier ist Deklaration und Definition
      // des Iterators zu Ende!
      // ========================================

      // Methoden der Klasse TListe,
      // die die Klasse Iterator benutzen:

      TListe::Iterator begin() const
      {  return Iterator(Anfang); }

      TListe::Iterator end() const
      {  return Iterator(); } // NULL-Iterator

      void erase(Iterator& pos) // Element löschen
      {
         if (pos.aktuell == Anfang)
         {
            pop_front();
            pos.aktuell = Anfang; // neuer Anfang
         }
         else
            if (pos.aktuell == Ende)
            {
               pop_back();
               pos.aktuell = Ende;
            }
            else
            {
               // zwischen 2 Elementen ausketten
               pos.aktuell->Next->Prev = pos.aktuell->Prev;
               pos.aktuell->Prev->Next = pos.aktuell->Next;
               Listenelement *temp = pos.aktuell;
               pos.aktuell = pos.aktuell->Next;
               delete temp;
               Anzahl--;
            }
      }

      // Vor pos einfügen
      TListe::Iterator insert(TListe::Iterator pos, const T& Wert)
      {
         if (pos == begin())
         {
            push_front(Wert);
            return Iterator(Anfang);
         }
         if (pos == end())
         {
            push_back(Wert);
            return Iterator(Ende);
         }
         // zwischen 2 Elementen einketten
         Listenelement *temp = new Listenelement;
         temp->Daten = Wert;
         temp->Next = pos.aktuell;
         temp->Prev = pos.aktuell->Prev;
         pos.aktuell->Prev->Next=temp;
         pos.aktuell->Prev = temp;
         Anzahl++;
         return Iterator(temp);
      }

      const T& get_element(TListe::Iterator pos) const
      {
         return pos.aktuell->Daten;
      }
	const T& get_element(TListe::Iterator pos) const{

		return  NULL;
	}
	TListe::Iterator insert(TListe::Iterator pos, const T& Wert){

		return  NULL;
	}
};

// ===== Implementierung der Klasse TListe =====
// soweit nicht schon geschehen

template<class T>           // Konstruktor
inline TListe<T>::TListe():Ende(NULL), Anfang(NULL), Anzahl(0) { }

template<class T>           // Kopierkonstruktor
inline TListe<T>::TListe(const TListe<T>& L):Ende(NULL), Anfang(NULL), Anzahl(0)
{
   Listenelement *temp = L.Ende;
   while(temp)
   {
      push_front(temp->Daten);
      temp = temp->Prev;
   }
}

template<class T>           // Destruktor
inline TListe<T>::~TListe()
{
   // while(!empty())
   //    pop_front();
}

template<class T>           // Zuweisungsoperator
inline TListe<T>& TListe<T>::operator=(const TListe<T>& L)
{
   if (this != &L) // Selbstzuweisung ausschließen
   {
      while(!empty())
         pop_front(); // alles löschen
      // ... und neu aufbauen
      Listenelement *temp = L.Ende;
      while(temp)
      {
         push_front(temp->Daten);
         temp = temp->Prev;
      }
   }
   return *this;
}

template<class T>
inline void TListe<T>::push_front(const T& Dat)
{
   Listenelement *temp = new Listenelement;
   temp->Daten = Dat;
   temp->Prev = NULL;
   temp->Next = Anfang;
   if (!Anfang)
      Ende=temp; // einziges Element
   else
      Anfang->Prev = temp;
   Anfang = temp;
   Anzahl++;
}

template<class T>
inline void TListe<T>::push_back(const T& Dat)
{
   Listenelement *temp = new Listenelement;
   temp->Daten = Dat;
   temp->Prev = Ende;
   temp->Next = NULL;
   if (!Ende)
      Anfang=temp; // einziges Element
   else
      temp->Prev->Next = temp;
   Ende = temp;
   Anzahl++;
}

template<class T>
inline void TListe<T>::pop_front()
{
   assert(!empty());
   Listenelement *temp = Anfang;
   Anfang = temp->Next;
   if (!Anfang)
      // d.h. kein weiteres Element vorhanden
      Ende = NULL;
   else
      Anfang->Prev = NULL;
   delete temp;
   Anzahl--;
}

template<class T>
inline void TListe<T>::pop_back()
{
   assert(!empty());
   Listenelement *temp = Ende;
   Ende = temp->Prev;
   if (!Ende)
      // d.h. kein weiteres Element vorhanden
      Anfang = NULL;
   else
      Ende->Next = NULL;
   delete temp;
   Anzahl--;
}

template<class T>
inline T& TListe<T>::front()
{
   assert(!empty());
   return Anfang->Daten;
}

template<class T>
inline const T& TListe<T>::front() const
{
   assert(!empty());
   return Anfang->Daten;
}

template<class T>
inline T& TListe<T>::back()
{
   assert(!empty());
   return Ende->Daten;
}

template<class T>
inline const T& TListe<T>::back() const
{
   assert(!empty());
   return Ende->Daten;
}

#endif // TListe_H
