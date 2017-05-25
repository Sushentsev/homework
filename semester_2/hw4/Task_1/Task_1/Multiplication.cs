﻿namespace Task_1
{
    /// <summary>
    /// Узел-умножение
    /// </summary>
    public class Multiplication : Operator
    {
        /// <summary>
        /// Конструктор для класса
        /// </summary>
        /// <param name="leftChild">Левый узел</param>
        /// <param name="rightChild">Правый узел</param>
        public Multiplication(Node leftChild, Node rightChild) : base(leftChild, rightChild)
        {

        }

        /// <summary>
        /// Вычисление дерева, начиная с данной вершины
        /// </summary>
        public override int Calculate() => leftChild.Calculate() * rightChild.Calculate();

        /// <summary>
        /// Печать дерева в виде строки, начиная с данной вершины
        /// </summary>
        public override string Print() => "( * " + leftChild.Print() + " " + rightChild.Print() + " )";
    }
}
