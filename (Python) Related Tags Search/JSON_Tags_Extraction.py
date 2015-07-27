__author__ = 'Apoorv'

import json
import operator

class Vertex:
    def __init__(self, node):
        self.id = node
        self.adjacent = {}

    def __repr__(self):
        # return str(self.id) + ' adjacent: ' + str([x.id for x in self.adjacent])
        return str(self.id)

    #def __str__(self):
    #    return str(self.id) + ' adjacent: ' + str([x.id for x in self.adjacent])

    def add_neighbor(self, neighbor, weight=0):
        if neighbor in self.adjacent.keys():
            self.adjacent[neighbor] += weight
        else:
            self.adjacent[neighbor] = weight

    def get_connections(self):
        return self.adjacent.keys()

    def get_id(self):
        return self.id

    def get_weight(self, neighbor):
        return self.adjacent[neighbor]
    
    def get_star_neighbors(self, threshold = 2) :
        neighbors = []
        for x in self.adjacent:
            if self.get_weight(x) >= threshold:
                neighbors.append([x, self.get_weight(x)])
        sorted_neighbors = sorted(neighbors, key=operator.itemgetter(1))
        sorted_neighbors.reverse()
        sorted_neighbors = sorted_neighbors[1:11]
        #sorted_neighbors = sorted_neighbors[1:]
        print 'Top 10 related keywords\n'
        return sorted_neighbors
class Graph:
    def __init__(self):
        self.vert_dict = {}
        self.num_vertices = 0

    def __iter__(self):
        return iter(self.vert_dict.values())

    def add_vertex(self, node):
        self.num_vertices = self.num_vertices + 1
        new_vertex = Vertex(node)
        self.vert_dict[node] = new_vertex
        return new_vertex

    def get_vertex(self, n):
        if n in self.vert_dict:
            return self.vert_dict[n]
        else:
            return None

    def add_edge(self, frm, to, cost = 0):
        if frm not in self.vert_dict:
            self.add_vertex(frm)
        if to not in self.vert_dict:
            self.add_vertex(to)

        self.vert_dict[frm].add_neighbor(self.vert_dict[to], 0.5)
        self.vert_dict[to].add_neighbor(self.vert_dict[frm], 0.5)

    def get_vertices(self):
        return self.vert_dict.keys()

    def search(self, keyword):
        return self.get_vertex(keyword).get_star_neighbors()

if __name__ == '__main__':
  g = Graph()
  pages = []
  for y in range(1,151):
    fp = open('Pages/page_' + ("%04d" % y) + '.txt')
    data = fp.read()
    try:
       data = json.loads(data)
    except Exception as e:
       pass

    try:
        for item in data['items']:
            # print item['tags']
            for tagx in item['tags']:
                # if tag not in g.get_vertices():
                #     g.add_vertex(tag)
                for tagy in item['tags']:
                    g.add_edge(tagx, tagy)
                    #print(tagx ,tagy)

    except Exception:
        pass

  while(True):
    keyword = raw_input('Enter a keyword : ')
    try: 
        sorted_neighbors = g.search(keyword)
        i = 1
        for x in sorted_neighbors:
        #print '%25s %4s\n' % (str(x[0]), str(x[1]))
           print str(i) + ". " + str(x[0])
           i+= 1
           #print "IIIIIIIIIIIIIIIIIIIII"
    except Exception as e:
        print 'Keyword not found. Please try again!'


    print '---------------------------------\n'
  #  g = Graph()
  #  g.add_vertex('a')
  #  g.add_edge('a', 'b', 7)

