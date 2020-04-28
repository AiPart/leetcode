/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmd = [](ListNode* node1, ListNode* node2) {
            return node1->val > node2->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmd)> queue(cmd);
        
        //for (auto& head: lists) {
            //auto& node = head;   // 会导致超时
        for (auto head: lists) {
            auto node = head;
            if (node) {
                queue.push(node);
            }
        }
        ListNode dummyNode;
        ListNode* node = &dummyNode;
        while (!queue.empty()) {
            //auto& top = queue.top(); // 也会导致超时！应该是死循环了
            auto top = queue.top();
            queue.pop();

            node->next = top;
            node = node->next;
            if (top->next) {
                queue.push(top->next);
            }
        }        
        return dummyNode.next;
    }
};
