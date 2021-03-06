﻿using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Task_4.Tests
{
    [TestClass]
    public class StackOnListTest
    {
        [TestInitialize]
        public void Initialize()
        {
            stack = new StackOnList();
        }

        [TestMethod]
        public void PushOneValueTest()
        {
            stack.Push(2);
            Assert.IsFalse(stack.IsEmpty());
        }

        [TestMethod]
        public void PushTwoValuesTest()
        {
            stack.Push(1);
            stack.Push(2);
            Assert.IsFalse(stack.IsEmpty());
        }

        [TestMethod]
        public void PopWithOnePushedValueTest()
        {
            stack.Push(1);
            Assert.AreEqual(1, stack.Pop());
        }

        [TestMethod]
        public void PopWithTwoPushedValueTest()
        {
            stack.Push(1);
            stack.Push(2);
            Assert.AreEqual(2, stack.Pop());
        }

        [TestMethod]
        [ExpectedException(typeof(Exception))]
        public void EmptyStackPopTest()
        {
            stack.Pop();
        }

        [TestMethod]
        public void LengthOfStackWithThreeElementsTest()
        {
            stack.Push(1);
            stack.Push(2);
            stack.Push(3);
            Assert.AreEqual(3, stack.GetLength());
        }

        [TestMethod]
        public void LengthOfEmptyStackTest()
        {
            Assert.AreEqual(0, stack.GetLength());
        }

        private StackOnList stack;
    }
}
