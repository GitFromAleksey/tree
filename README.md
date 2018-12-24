# tree
tree for 2gis

Описание формата данных для хранения дерева в файле.

1. каждый узел дерева помещается в квадратные скобки []
2. [tag=<data type>,val=<data>] 
	Внутри скобок располагаются: 
	оптисание типа хранимых данных tag=<data type> и данные val=<data>
3. дочерние узлы располагаются внутри скобок родительского узла, формат дочерних узлов такой же: [tag=<data type>,val=<data>[tag=<data type>,val=<data>]]
4. пример: 
	[tag=string,val=root[tag=int,val=1[tag=float,val=1.0[tag=float,val=1.11]][tag=float,val=1.1][tag=float,val=1.2]][tag=int,val=2[tag=float,val=2.0]]]