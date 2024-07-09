/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicatesUnsorted(struct ListNode* head){
    int* count = malloc(sizeof(int)*2000000);
    struct ListNode *current = head;
    struct ListNode *result = head;
    int i = 0;

    for (int i = 0 ; i< 6000; i++)
    {
        count[i] = 0;
    }

    while (current != NULL)
    {
        count[current->val] = count[current->val] + 1;
        current = current->next;
    }

    while (result != NULL && count[result->val] > 1)
    {
        result = result->next;
        head = result;
    }

    while (result != NULL)
    {
        if (count[result->val] == 1)
        {
            if (result->next != NULL)
            {
		// This conditional allows us to escape the above if clause
                if (count[result->next->val] > 1)
                {
                    if (result->next->next != NULL)
                    {
                        while (result->next->next != NULL && count[result->next->next->val] > 1)
                        {
                            result->next = result->next->next;
                        }
                        
                        struct ListNode *temp;
                        temp = result->next->next;
                        result->next = temp;
                        
                    }
                    else
                    {
                        result->next = NULL;
                    }
                }
            }
            else
            {
                result->next = NULL;
            }
        }
        
        result = result->next;
    }

    return head;
}
