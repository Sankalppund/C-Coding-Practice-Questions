struct ListNode* mergeTwoLL(struct ListNode*h1, struct ListNode*h2){
    
    if(h1==h2){
        return h1;
    }
    if(!h1){
        return h2;
    }
    if(!h2){
        return h1;
    }
    if(h1->val<h2->val){
        h1->next = mergeTwoLL(h1->next,h2);
        return h1;
    }
    else{
        h2->next = mergeTwoLL(h1,h2->next);
        return h2;
    } 
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    
    if(listsSize==0){
        return NULL;
    }
    if(listsSize==1){
        return lists[0];
    }
    int i,j;
    for(i=0,j=listsSize-1;i<j;i++,j--){
        lists[i]=mergeTwoLL(lists[i],lists[j]);
        listsSize--;
    }
    
    return mergeKLists(lists,listsSize);
}