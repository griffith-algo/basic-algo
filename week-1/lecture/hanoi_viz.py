# -*- coding: utf-8 -*-
"""
Created on Jan 31 15:18:03 2022

@author: Vinod K. Batra
"""
import sys
from vpython import *

###########################################################
POLE_LENGTH = 6
DISKS = []
COLORS = [color.red, color.green, color.blue, color.orange, color.yellow, color.magenta]
deltaRadius = 0.1
j = 1
###############################################################

def setupDisks(numDisks, poleRadius=0.2):

    """Create the poles and disks used by the VPython Tower of Hanoi animation.

    Args:
        numDisks (object): The numDisks input used by this function.
        poleRadius (float): The poleRadius input used by this function.

    Returns:
        None: This function updates data or prints results and does not return a value.
    """
    cylinder(color=color.white, pos=vector(-POLE_LENGTH, -4., -2),
             radius=poleRadius, length=POLE_LENGTH*2, axis=vector(1, 0, 0))

    cylinder(color=color.white, pos=vector(-POLE_LENGTH, -4, -2),
             radius=poleRadius, length=POLE_LENGTH, axis=vector(0, 1, 0))
    cylinder(color=color.white, pos=vector(0, -4, -2),
             radius=poleRadius, length=POLE_LENGTH, axis=vector(0, 1, 0))
    cylinder(color=color.white, pos=vector(POLE_LENGTH, -4, -2),
             radius=poleRadius, length=POLE_LENGTH, axis=vector(0, 1, 0))

    text(text="Source", height=0.5, pos=vector(-7, 2.5, -2))
    text(text="Temp", height=0.5, pos=vector(-1, 2.5, -2))
    text(text="Destination", height=0.5, pos=vector(5, 2.5, -2))

    for i in range(numDisks):
        disk = ring(color=COLORS[i], radius=1-deltaRadius*i, thickness=0.3, pos=vector(-POLE_LENGTH, -3+i, -2),
                    axis=vector(0, -1, 0))
        DISKS.append(disk)


def toh(n, NUMBER_DISKS, source, temp, dest, sceneCapture):

    """Animate the Tower of Hanoi solution recursively.

    Args:
        n (int): The n input used by this function.
        NUMBER_DISKS (object): The NUMBER_DISKS input used by this function.
        source (object): The source input used by this function.
        temp (object): The temp input used by this function.
        dest (str): The dest input used by this function.
        sceneCapture (bool): The sceneCapture input used by this function.

    Returns:
        None: This function updates data or prints results and does not return a value.
    """
    if n == 1:
        print("Moving disk {} from  {} to  {}. ".format(n, source, dest))
        moveDisk(n, NUMBER_DISKS, dest, sceneCapture)
        return
    toh(n-1, NUMBER_DISKS, source, dest, temp, sceneCapture)
    print("Moving disk {} from  {} to  {}. ".format(n, source, dest))
    moveDisk(n, NUMBER_DISKS, dest, sceneCapture)
    toh(n-1, NUMBER_DISKS, temp, source, dest, sceneCapture)

def moveDisk(n, NUMBER_DISKS, end, sceneCapture, dT=0.5):
    """Move one disk to its next pole in the animation.

    Args:
        n (int): The n input used by this function.
        NUMBER_DISKS (object): The NUMBER_DISKS input used by this function.
        end (object): The end input used by this function.
        sceneCapture (bool): The sceneCapture input used by this function.
        dT (float): The dT input used by this function.

    Returns:
        None: This function updates data or prints results and does not return a value.
    """
    sleep(dT)
    global j

    if end == 'destination':
        DISKS[NUMBER_DISKS-n].pos = vector(POLE_LENGTH, -0.8*n, -2)

        if sceneCapture:
            print(j)
            scene.capture("image" + str(j).zfill(2))
            j += 1
    elif end == 'temp':
        DISKS[NUMBER_DISKS-n].pos = vector(0, -0.8*n, -2)
        if sceneCapture:
            print(j)
            scene.capture("image" + str(j).zfill(2))
            j += 1
    elif end == 'source':
        DISKS[NUMBER_DISKS-n].pos = vector(-POLE_LENGTH, -0.8*n, -2)
        if sceneCapture:
            print(j)
            scene.capture("image" + str(j).zfill(2))
            j += 1

def main():
    """Run the small demonstration for this teaching example.

    Returns:
        None: This function updates data or prints results and does not return a value.
    """
    numberofdisks = 6 # Don't use more than 6
    setupDisks(numberofdisks)
    sceneCapture = False # Set to True to save images
    if sceneCapture:
        scene.capture("image0")# Starting Image
    dt = 1 # change this speed up or slow down animation
    keepRunning = False # Change it to True to keep going

    while True:
        rate(100)
        sleep(dt)
        toh(numberofdisks, numberofdisks, 'source', 'temp',  'destination', sceneCapture)
        print("Disk Transfer Completed. Swapping destination")
        sleep(dt)
        toh(numberofdisks, numberofdisks, 'destination', 'temp', 'source', sceneCapture)# To move disks back to the original pole
        sleep(dt)

        if not keepRunning:
            break
        print("Disk Transfer Completed. Swapping destination")
    print("All Done")


if __name__ == '__main__':
    main()