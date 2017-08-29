#include "cnPtrQueue.h"
#include <cassert>
using namespace std;

namespace CS3358_FA15_A5P2
{
   cnPtrQueue::cnPtrQueue():numItems(0)
   {}
 
   bool cnPtrQueue::empty()const
   {
      return (outStack.empty() && inStack.empty());
   }

   size_t  cnPtrQueue::size()const
   {
      return numItems;
   }

   CNode* cnPtrQueue::front()
   {
      assert(!inStack.empty() || !outStack.empty());

      if(outStack.empty())
      {
         while(!inStack.empty())
         {
            outStack.push(inStack.top());
            inStack.pop();
         }
      }
      return outStack.top();
   }

   void cnPtrQueue::push(CNode* cnPtr)
   {
      inStack.push(cnPtr);
      ++numItems;
   }

   void cnPtrQueue::pop()
   {
      assert(!inStack.empty() || !outStack.empty());

      if(outStack.empty())
      {
         while(!inStack.empty())
         {
            outStack.push(inStack.top());
            inStack.pop();
         }
      }
      outStack.pop();
      --numItems;
   }
}

