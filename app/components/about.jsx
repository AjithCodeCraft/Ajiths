"use client";

import React, { useState, useEffect } from "react";
import Image from "next/image";
import { InfiniteMovingCards } from "@/components/ui/infinite-moving-cards";
import { Button } from "@/components/ui/Button";
import { Download } from "lucide-react";

// Testimonials data for InfiniteMovingCards component
const testimonials = [
  {
    quote:
      "It was the best of times, it was the worst of times, it was the age of wisdom, it was the age of foolishness, it was the epoch of belief, it was the epoch of incredulity, it was the season of Light, it was the season of Darkness, it was the spring of hope, it was the winter of despair.",
    name: "Charles Dickens",
    title: "A Tale of Two Cities",
  },
  {
    quote:
      "To be, or not to be, that is the question: Whether 'tis nobler in the mind to suffer The slings and arrows of outrageous fortune, Or to take Arms against a Sea of troubles, And by opposing end them: to die, to sleep.",
    name: "William Shakespeare",
    title: "Hamlet",
  },
  {
    quote: "All that we see or seem is but a dream within a dream.",
    name: "Edgar Allan Poe",
    title: "A Dream Within a Dream",
  },
  {
    quote:
      "It is a truth universally acknowledged, that a single man in possession of a good fortune, must be in want of a wife.",
    name: "Jane Austen",
    title: "Pride and Prejudice",
  },
  {
    quote:
      "Call me Ishmael. Some years ago—never mind how long precisely—having little or no money in my purse, and nothing particular to interest me on shore, I thought I would sail about a little and see the watery part of the world.",
    name: "Herman Melville",
    title: "Moby-Dick",
  },
];

// InfiniteMovingCards Demo Component
export function InfiniteMovingCardsDemo() {
  return (
    <div className="h-[40rem] rounded-md flex flex-col antialiased bg-white dark:bg-black dark:bg-grid-white/[0.05] items-center justify-center relative overflow-hidden">
      <InfiniteMovingCards items={testimonials} direction="right" speed="slow" />
    </div>
  );
}

// About Component with Scrambling Effect for Button
const About = () => {
  const [displayText, setDisplayText] = useState("Download Resume");
  const charset = "abcdefghijklmnopqrstuvwxyz";

  const randomChars = (length) => {
    return Array.from({ length }, () => charset[Math.floor(Math.random() * charset.length)]).join("");
  };

  const scramble = async (input) => {
    let prefix = "";
    for (let index = 0; index < input.length; index++) {
      await new Promise((resolve) => setTimeout(resolve, 50));
      prefix += input.charAt(index);
      setDisplayText(prefix + randomChars(input.length - prefix.length));
    }
  };

  const startScrambling = () => {
    scramble("Download Resume");
    setTimeout(() => {
      console.log("Submitted");
      window.open("/path/to/your/resume.pdf", "_blank"); // Update with your resume link
    }, displayText.length * 50);
  };

  useEffect(() => {
    setDisplayText("Download Resume");
  }, []);

  return (
    <>
      {/* Section 1 */}
      <section className="py-11 w-full px-6 lg:px-10 pt-32 sm:pt-24 md:pt-28 xl:pt-40" id="whychooseus">
        
        {/* Centered Title */}
        <div className="w-full flex justify-center mb-8">
          <h2 className="text-6xl font-extrabold text-[#c2410c] dark:text-[#c2410c]">
            About Me
          </h2>
        </div>

        <div className="flex flex-col lg:flex-row w-full items-center justify-center md:gap-10 gap-1">
          
          {/* Left Side Image */}
          <div className="relative flex justify-center items-center w-full h-[600px] max-w-[400px] mx-auto lg:ml-10">
            <Image
              src="/man.png"
              alt="Hero image"
              fill
              className="rounded-lg object-cover"
              sizes="(max-width: 768px) 100vw, (max-width: 1200px) 50vw, 33vw"
            />
          </div>

          {/* Right Side Content */}
          <div className="lg:w-1/2 w-full px-4">
            <p className="mb-4 text-3xl text-center lg:text-left text-white md:text-md">
              A software engineer, the modern-day architect of digital realms, navigates the ethereal landscapes of code, sculpting intangible structures that shape our technological world. With fingers poised over keyboards like virtuoso pianists, they compose symphonies of logic, their minds a labyrinth of algorithms and solutions. Their canvas is a screen, a vast expanse where lines of code dance in intricate patterns, weaving the fabric of programs and applications. Each keystroke is a brushstroke, crafting intricate architectures and breathing life into innovative designs. In this digital atelier, they don the mantle of problem solvers, confronting bugs and glitches like valiant knights in an ever-evolving quest for perfection.
            </p>

            {/* Download Resume Button */}
            <Button
              size="lg"
              className="text-base px-5 py-6 mt-6 bg-[#c2410c] text-white hover:bg-orange-600"
              onMouseEnter={startScrambling}
            >
              <Download className="mx-1" />
              {displayText}
            </Button>
          </div>
        </div>
      </section>
    </>
  );
};

export default About;
