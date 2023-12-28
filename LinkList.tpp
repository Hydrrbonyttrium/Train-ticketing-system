template <typename T>
LinkedList<T>::LinkedList() {
    // ����һ������ͷ�ڵ�Ŀ�����
    head = new ListNode<T>(T());
}

template <typename T>
LinkedList<T>::~LinkedList() {
    DestroyList();
}

template <typename T>
void LinkedList<T>::ListInsert(int i, const T& e) {
    ListNode<T>* current = head;
    int j = 0;

    while (current != nullptr && j < i - 1) {
        current = current->next;
        ++j;
    }

    if (current == nullptr || j > i - 1) {
        std::cerr << "����λ����Ч\n";
        return;
    }

    ListNode<T>* newNode = new ListNode<T>(e, current->next);
    current->next = newNode;
}

template <typename T>
void LinkedList<T>::ListDelete(int i, T& e) {
    ListNode<T>* current = head;
    int j = 0;

    while (current->next != nullptr && j < i - 1) {
        current = current->next;
        ++j;
    }

    if (current->next == nullptr || j > i - 1) {
        std::cerr << "ɾ��λ����Ч\n";
        return;
    }

    ListNode<T>* toDelete = current->next;
    current->next = toDelete->next;
    e = toDelete->data;
    delete toDelete;
}

template <typename T>
int LinkedList<T>::ListLength() const {
    int length = 0;
    ListNode<T>* current = head->next; // ����ͷ�ڵ�

    while (current != nullptr) {
        ++length;
        current = current->next;
    }

    return length;
}

template <typename T>
ListNode<T>* LinkedList<T>::GetElemPtr(int i) {
    if (i < 0 || i > ListLength()) {
        return nullptr;
    }

    ListNode<T>* current = head->next;
    for (int j = 1; j < i; ++j) {
        current = current->next;
    }

    return current;
}

template <typename T>
T LinkedList<T>::GetElem(int i) {
    ListNode<T>* ptr = GetElemPtr(i);
    if (ptr != nullptr) {
        return ptr->data;
    } else {
        throw std::runtime_error("λ����Ч���޷���ȡԪ��");
    }
}

template <typename T>
int LinkedList<T>::LocateElem(const T& e) {
    int index = 1;
    ListNode<T>* current = head->next;

    while (current != nullptr) {
        if (current->data == e) {
            return index;
        }
        current = current->next;
        ++index;
    }

    return 0; // ���û���ҵ�Ԫ�أ��򷵻�0
}

template <typename T>
void LinkedList<T>::ListTraverse(void (*visit)(const T&)) {
    ListNode<T>* current = head->next;

    while (current != nullptr) {
        visit(current->data);
        current = current->next;
    }
}

template <typename T>
void LinkedList<T>::print(const T& data) {
    std::cout << data << " ";
}

template <typename T>
void LinkedList<T>::DestroyList() {
    ListNode<T>* current = head;

    while (current != nullptr) {
        ListNode<T>* toDelete = current;
        current = current->next;
        delete toDelete;
    }
}
