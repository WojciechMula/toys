class TableBase(object):
    def __init__(self):
        self.header = []
        self.rows   = []

    def set_header(self, header):
        assert len(header) > 0
        self.header = header

    def add_row(self, row):
        assert len(row) == len(self.header)

        self.rows.append(row)


class RestructuredTextTableRenderer(object):

    def __init__(self, table):
        self.table   = table
        self.widths  = self._calculate_widths()
        self.padding = 1


    def get_header(self):
        return self.table.header


    def get_rows(self):
        return self.table.rows


    def _calculate_widths(self):

        width = [0] * len(self.get_header())

        for row in [self.get_header()] + self.get_rows():
            for index, image in enumerate(row):
                w = len(image)
                width[index] = max(w, width[index])

        return width


    def _render_separator(self, fill):

        assert len(fill) == 1

        result = '+'

        for width in self.widths:
            width = width + 2 * self.padding

            result += (fill * width) + '+'

        return result


    def _render_row(self, row):

        result  = '|'
        padding = ' ' * self.padding

        for image, width in zip(row, self.widths):
            result += '%s%*s%s|' % (padding, -width, image, padding)

        return result


    def get_image(self): # rest = RestructuredText

        lines  = []

        separator = self._render_separator('-')

        lines.append(separator)
        lines.append(self._render_row(self.get_header()))
        lines.append(self._render_separator('='))

        for row in self.get_rows():
            lines.append(self._render_row(row))
            lines.append(separator)

        return '\n'.join(lines)


class Table(TableBase):

    def __unicode__(self):

        renderer = RestructuredTextTableRenderer(self)
        return renderer.get_image()

    def __str__(self):

        renderer = RestructuredTextTableRenderer(self)
        return renderer.get_image()


if __name__ == '__main__':

    table = Table()

    table.set_header(["procedure", "size", "time"])
    table.add_row(["foo", "100", "0.5"])
    table.add_row(["bar", "105", "1.5"])
    table.add_row(["baz", "111", "0.2"])

    print table

