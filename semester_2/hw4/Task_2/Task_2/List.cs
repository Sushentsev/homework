﻿using System;

namespace Task_2
{
    /// <summary>
    /// Linked list
    /// </summary>
    public class List
    {
        /// <summary>
        /// The element of list
        /// </summary>
        private class ListElement
        {
            public ListElement Next { get; set; }
            public int Value { get; private set; }

            public ListElement(ListElement next, int value)
            {
                this.Next = next;
                this.Value = value;
            }

        }

        /// <summary>
        /// The first element of list
        /// </summary>
        private ListElement head;

        /// <summary>
        /// The length of list
        /// </summary>
        private int length;

        /// <summary>
        /// Adding new element to list
        /// </summary>
        /// <param name="value">The value for adding</param>
        public virtual void Add(int value)
        {
            var newElement = new ListElement(head, value);
            head = newElement;
            ++length;
        }

        /// <summary>
        /// Checking list on emptiness
        /// </summary>
        /// <returns>True if list is empty otherwise false</returns>
        public bool IsEmpty() => length == 0;

        /// <summary>
        /// Getting length of list
        /// </summary>
        /// <returns>The length of list</returns>
        public int GetLength() => length;

        /// <summary>
        /// Checking value on belonging
        /// </summary>
        /// <param name="value">The value for searching</param>
        /// <returns>True if valur belongs otherwise false</returns>
        public bool IsContained(int value)
        {
            var cursor = head;

            for (var i = 0; i < length; ++i)
            {
                if (cursor.Value == value)
                {
                    return true;
                }
                cursor = cursor.Next;
            }

            return false;
        }

        /// <summary>
        /// Removing list
        /// </summary>
        public void RemoveList()
        {
            head = null;
            length = 0;
        }

        /// <summary>
        /// Removing element from list
        /// </summary>
        /// <param name="value">The value for removing</param>
        public virtual void RemoveElement(int value)
        {
            if (!IsContained(value))
            {
                throw new Exception("The value is not contained in the list!");
            }

            if (head.Value == value)
            {
                head = head.Next;
                --length;
                return;
            }

            var cursor = head;

            for (int i = 0; i < length - 1; ++i)
            {
                if (cursor.Next.Value == value)
                {
                    cursor.Next = cursor.Next.Next;
                    --length;
                    return;
                }

                cursor = cursor.Next;
            }
        }

        /// <summary>
        /// Getting the first value in list
        /// </summary>
        /// <returns>The first value in list</returns>
        public int Peek()
        {
            if (IsEmpty())
            {
                throw new Exception("List is empty!");
            }

            return head.Value;
        }
    }
}
