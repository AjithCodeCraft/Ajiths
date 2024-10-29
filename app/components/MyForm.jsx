import { useState } from 'react';
import { GlobeDemo } from './globedemo';

const MyForm = () => {
  const [name, setName] = useState('');
  const [email, setEmail] = useState('');
  const [phone, setPhone] = useState('');
  const [message, setMessage] = useState('');

  const handleSubmit = (e) => {
    e.preventDefault();
    console.log({ name, email, phone, message });
    // Add your form submission logic here
  };

  return (
    <section id="contact" className="py-16 bg-gradient-to-b from-black-800 to-[#c2410c] text-white">
      <div className="text-center mb-8">
        <h1 className="text-4xl font-cursive mb-2">Get in <span className="text-[#c2410c]">Touch with us</span></h1>
        <h3>Lorem Ipsum is simply dummy text of the printing and typesetting industry</h3>
      </div>
      <div className="container mx-auto flex flex-wrap">
        {/* Globe Component on the left */}
        <div className="w-full md:w-1/2 p-4">
          <GlobeDemo/>
        </div>

        {/* Form Component on the right */}
        <div className="w-full md:w-1/2 p-4">
          <form onSubmit={handleSubmit} className="flex flex-wrap">
            <div className="mb-4">
              <label htmlFor="name" className="block text-lg">Your Name</label>
              <input
                type="text"
                id="name"
                placeholder="Enter Name"
                className="form-control w-full p-2 border border-gray-300 rounded bg-gray-700 text-white"
                value={name}
                onChange={(e) => setName(e.target.value)}
                required
              />
            </div>
            <div className="mb-4">
              <label htmlFor="email" className="block text-lg">Email Address</label>
              <input
                type="email"
                id="email"
                placeholder="Enter Email id"
                className="form-control w-full p-2 border border-gray-300 rounded bg-gray-700 text-white"
                value={email}
                onChange={(e) => setEmail(e.target.value)}
                required
              />
            </div>
            <div className="mb-4">
              <label htmlFor="telephone" className="block text-lg">Mobile No.</label>
              <input
                type="tel"
                id="telephone"
                placeholder="Enter 10-digit mobile no."
                className="form-control w-full p-2 border border-gray-300 rounded bg-gray-700 text-white"
                value={phone}
                onChange={(e) => setPhone(e.target.value)}
                required
              />
            </div>
            <div className="mb-4">
              <label htmlFor="description" className="block text-lg">Message</label>
              <textarea
                id="description"
                placeholder="Enter Your Message"
                className="form-control w-full h-32 p-2 border border-gray-300 rounded bg-gray-700 text-white"
                value={message}
                onChange={(e) => setMessage(e.target.value)}
                required
              />
            </div>
            <button type="submit" className="btn bg-[#c2410c] text-white border border-white px-4 py-2 rounded hover:bg-orange-600">
              <i className="fa fa-paper-plane" aria-hidden="true"></i> Send Message
            </button>
          </form>
        </div>
      </div>
    </section>
  );
};

export default MyForm;
