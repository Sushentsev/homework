﻿using System;
using Task_1.Interfaces;

namespace Task_1.Classes
{
    /// <summary>
    /// Computer of local network.
    /// </summary>
    public class Computer : IComputer
    {
        /// <summary>
        /// Computer infecting.
        /// </summary>
        public bool IsInfected { get; private set; }

        /// <summary>
        /// Operation system.
        /// </summary>
        public OS oS { get; private set; }

        /// <summary>
        /// Probability of infection.
        /// Integer number from [0; 100].
        /// </summary>
        private int probabitityOfInfection;

        /// <summary>
        /// Constructor for computer class.
        /// </summary>
        /// <param name="oS">Operation system.</param>
        public Computer(OS oS)
        {
            this.oS = oS;
            this.probabitityOfInfection = GetProbabitityOfInfection();
        }

        /// <summary>
        /// Generating random number.
        /// </summary>
        public Random random = new Random(DateTime.Now.Millisecond);

        /// <summary>
        /// Trying to infect a computer.
        /// </summary>
        public void TryToInfect()
        {
            if (random.Next(0, 100) <= probabitityOfInfection)
            {
                IsInfected = true;
            }
        }

        /// <summary>
        /// Getting random probability of infection which depends on file system.
        /// The number represents the vulnerability of the system in percentage.
        /// </summary>
        /// <returns>Probability of infection.</returns>
        private int GetProbabitityOfInfection()
        {
            switch (oS)
            {
                case OS.Windows:
                    return random.Next(50, 70);
                case OS.Linux:
                    return random.Next(10, 25);
                case OS.MacOs:
                    return random.Next(25, 40);
                case OS.Embox:
                    return random.Next(0, 10);
                case OS.SafeOS:
                    return 0;
                default:
                    return 100;
            }
        }
    }
}