#!/usr/bin/env python3

import os
from pathlib import Path
from PIL import Image, ImageDraw


class Frame:
    def __init__(self, x, y, image):
        self.x = x
        self.y = y
        self.w = image.size[0]
        self.h = image.size[1]
        self.image = image


class Application:
    def __init__(self, inputdir, outputdir, n = 8):
        self.n = n
        self.width  = None
        self.height = None
        self.hspace = 4
        self.vspace = 10
        self.margin = 10
        self.inputdir = Path(inputdir)
        self.outputdir = Path(outputdir)
        assert self.inputdir.exists(), self.inputdir
        assert self.outputdir.exists()
        self.__load_frames()
        self.__load_background()
        self.__prepare_image()
        self.output_frame = 0

    def __load_frames(self):
        self.frames = {}

        prefix = 'frame'
        for path in Path(self.inputdir).glob(f"{prefix}*"):
            number = int(path.name[len(prefix):len(prefix) + 2])
            img = Image.open(path)
            x = 120
            y = 0
            s = img.height
            img = img.crop((x, y, x + s, y + s))
            img = img.resize((100, 100))
            self.frames[number] = img
            if self.width is None:
                self.width, self.height = img.size

        min_frame = 0
        max_frame = 50
        assert self.frames
        self.frames = [self.frames[i] for i in range(min_frame, max_frame, 2)]


    def __load_background(self):
        self.simd = simd = Image.open('simd.png')
        self.sisd = sisd = Image.open('sisd.png')

        self.sisd_y = self.margin + sisd.height + self.margin
        self.simd_y = self.sisd_y + self.height + 2*self.margin + self.simd.height + self.margin

        width = self.n * self.width + (self.n - 1) * self.hspace
        width = max(width, simd.width, sisd.width) + 2 * self.margin

        height = self.simd_y + self.height + self.margin
        img = Image.new('RGB', (width, height))

        draw = ImageDraw.Draw(img)
        draw.rectangle((0, 0, img.width, img.height), fill='#fff')

        img.paste(sisd, (self.margin + (width - sisd.width) // 2, self.margin))
        img.paste(simd, (self.margin + (width - simd.width) // 2, self.sisd_y + self.height + 2*self.margin))

        self.background = img



    def __prepare_image(self):
        self.cell = {}
        for j in range(2):
            self.cell[j] = [None] * self.n
            if j == 0:
                Y = self.sisd_y
            else:
                Y = self.simd_y
            
            for i in range(self.n):
                x = self.margin + i * (self.width + self.hspace)
                y = Y
                self.cell[j][i] = Frame(x, y, self.frames[0])

    
    def save(self):
        for j in range(2):
            for i in range(self.n):
                img = self.cell[j][i]
                draw = ImageDraw.Draw(self.background)
                draw.rectangle([img.x - 1, img.y - 1, img.x + img.w, img.y + img.h], outline='#555')

                self.background.paste(img.image, (img.x, img.y))
                
        path = self.outputdir / ('outframe%05d.pnm' % (self.output_frame))
        self.output_frame += 1
        self.background.save(path)


    def run(self):
        # prepare background
        self.save()

        # SISD animation
        for i in range(self.n):
            img = self.cell[0][i]
            for frame in self.frames:
                img.image = frame
                self.save()

        sisd_count = self.output_frame

        # SIMD animation
        for frame in self.frames:
            for i in range(self.n):
                img = self.cell[1][i]
                img.image = frame
            self.save()

        frames = []
        for i in range(self.output_frame):
            path = self.outputdir / ('outframe%05d.pnm' % i)
            print(path)
            frames.append(Image.open(path))

        print('saving')
        duration = [5] * (len(frames))
        duration[-1] = 1000
        frames[0].save(self.outputdir / 'out.gif',
                       save_all=True,
                       append_images=frames[1:],
                       duration=duration,
                       loop=0)
            


app = Application('input', 'output')
app.run()
