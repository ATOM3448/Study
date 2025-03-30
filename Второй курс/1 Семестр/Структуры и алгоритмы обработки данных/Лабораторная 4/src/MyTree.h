namespace MyTask
{
	class MyTree
	{
	public:
		//���������
		struct Tree
		{
			int item;
			Tree* parent;
			Tree* left;
			Tree* right;
		};

		//������
		Tree* root;

		//�������������
		MyTree();

		//������ ������
		~MyTree();

		//����� ��������
		Tree* search_tree(Tree* node, int info);

		//����� ������(���������� ����� �������)
		int travel_tree_sum(Tree* node);

		//����� ������(����� � �������)
		void travel_tree_print_boring(Tree* node, int level = 0);

		//����� ������(������� ������)
		void travel_tree_clear(Tree* node);

		//��������� ������������� ��������
		Tree* max_of_tree(Tree* node);

		//��������� ������������ ��������
		Tree* min_of_tree(Tree* node);

		//�������
		void insert_tree(Tree** node, int info, Tree* parent);

		//��������
		void remove_tree(Tree* node);
	};
}
