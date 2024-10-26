"use client";
import Head from 'next/head';
import Header from './components/header';
import { Spotlight } from '@/components/ui/Spotlight';
import Image from 'next/image';
import { Facebook, Linkedin, ExternalLink, Download } from "lucide-react";
import Link from "next/link";
import { Button } from '@/components/ui/Button';
import { useState, useEffect } from 'react';
import { FlipWords } from '@/components/ui/flip-words';
import About from './components/about';

export default function Home() {
  const links = [
    { name: "GitHub", link: "", icon: <Facebook /> },
    { name: "Linkedin", link: "", icon: <Linkedin /> },
    { name: "External", link: "", icon: <ExternalLink /> },
  ];

  const [displayText, setDisplayText] = useState('Download Resume');
  const charset = "abcdefghijklmnopqrstuvwxyz";

  const randomChars = (length) => {
    return Array.from(
      { length },
      () => charset[Math.floor(Math.random() * charset.length)]
    ).join("");
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
    scramble('Download Resume');
    setTimeout(() => {
      console.log("Submitted");
      window.open('/path/to/your/resume.pdf', '_blank'); // Update with your resume link
    }, displayText.length * 50);
  };

  useEffect(() => {
    setDisplayText('Download Resume');
  }, []);

  return (
    <>
      <Head>
        <meta charSet="utf-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1" />
      </Head>
      <main className="py-10 w-max-w-4xl	 px-6 lg:px-10 pt-3 sm:pt-24 md:pt-28 xl:pt-3">
        <Header />
        <div className="h-screen w-full flex items-center justify-between bg-black/[0.96] dark:bg-black relative overflow-hidden">
          <Spotlight
            className="top-[5rem] left-3 md:left-40"
            fill="#c2410c"
          />

          {/* Left Side Content */}
          <div className="flex flex-col items-start p-4 flex-grow">
            <h1 className="max-w-lg text-3xl font-semibold leading-loose text-gray-400 dark:text-white">Hii I am</h1>
            <h1 className="text-4xl font-extrabold text-white dark:text-white">Ajith S</h1>

            {/* Flipping Words Effect */}
            <h1 className="font-rubik text-[#c2410c] text-6xl name_underline max-sm:text-6xl font-bold whitespace-nowrap mt-8">
              <FlipWords words={["Software Developer","UI Designer", "Generative AI", "Gamer by Passion", "Video Editor"]} />
            </h1>

            {/* Social Links */}
            <div className="flex space-x-7 mt-6">
              {links.map((itm, indx) => (
                <Link 
                  key={indx}
                  target="_blank"
                  href={itm.link}
                  className="border border-gray-300 rounded-full p-2 hover:bg-gray-200 transition duration-300"
                >
                  {itm.icon}
                </Link>
              ))}
            </div>

            {/* Download Resume Button */}
            <Button size={'lg'} className='text-base px-5 py-6 mt-6 bg-[#c2410c] text-white hover:bg-orange-600' onMouseEnter={startScrambling}>
              <Download className="mx-1" />
              {displayText} 
            </Button>
          </div>

          {/* Hero Image */}
          <div className="relative flex justify-center items-center w-full h-[600px] max-w-[400px] mx-auto lg:ml-10">
            <Image
              src="/man.png"
              alt="Hero image"
              fill
              className="rounded-lg object-cover"
              sizes="(max-width: 768px) 100vw, (max-width: 1200px) 50vw, 33vw"
            />
          </div>
        </div>

        {/* About Section */}
        <About/>
      </main>
    </>
  );
}
