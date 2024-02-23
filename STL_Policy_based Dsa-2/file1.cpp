//using out own Node_update class
// template<class Node_CItr,
// 	 class Node_Itr,
// 	 class Cmp_Fn,
// 	 class _Alloc>
// struct my_node_update
// {
//     typedef my_type metadata_type;

//     void operator()(Node_Itr it, Node_CItr end_it)
//     {
//         ...
//     }
// };

// Let's consider how this class works. Policy based tree, which is using update 
// policy will additionally keep in node one variable of type my_type. When the tree 
// is rebuilt, part of the metadata spoils, so for each node, which could be damaged 
// applied the operator (). At the same time this operator begins to be applied firstly 
// to the leaves, that is, we guarantee that if () is applied to the node, its metadata 
// can be damaged, but the metadata of its children will be intact. The function has two 
// arguments let's learn them.
