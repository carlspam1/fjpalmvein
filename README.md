# fjpalmvein
Fujitsu Palm Vein USB driver (GPLv2)

The Fujitsu palm vein scanner is a USB device that takes pictures of a palm.
The pictures are taken in the visible and infra red spectra.
Downstream software takes the pictures and derives a model from the veins which can then be searched for a match.
In other words, the driver enables the use of a device that can be used to verify identity. Very handy.

The only drivers available online are Windows MSI and the Linux ones were nowhere to be found, or were binaries locked to an obsolete kernel.

However, recently, my client bought a device from a Fujitsu that came with the Linux driver. 
The Linux driver, it turns out, came in source code form and with a GPLv2 license, so Im posting the code here under those terms.

You will need to build it yourself, and make sure it's built to suit the kernel(s) you run on your equipment.

Note that the downstream software referred to above is non-trivial.
In the case of Linux there are several object files and you will likely need a PalmSecure SDK to get from the driver to a useful application.
So this is probably mostly useful for someone with bits of the SDK but who are missing the actual driver - like I was until this morning. 

The PalmSecure SDK is available from Fujitsu resellers for $$$.
But if you look hard enough you can find what you need. Check out project "Segovia" on github by NRLakin.
