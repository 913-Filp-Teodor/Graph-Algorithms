from random import randint
import time

class Graph:
    def __init__(self):
        self.neighs = {}

    def addVertex(self, vertex):
        if vertex not in self.neighs:
            self.neighs[vertex] = []
    
    def isInGraph(self, vertex):
        return vertex in self.neighs

    def parseX(self):
        return self.neighs.keys()

    def addEdge(self, src, dest):
        if not self.isInGraph(src) or not self.isInGraph(dest):
            raise ValueError("vertex not in graph")
        self.neighs[src].append(dest)
    
    def getOutboundVertices(self, src):
        if not self.isInGraph(src):
            raise ValueError("vertex not in graph")
        else: return self.neighs[src]

    def getInboundVertices(self, dest):
        srcs = []
        for x in self.neighs.keys():
            if dest in self.neighs[x]:
                srcs.append(x)

        return srcs

    def existsEdge(self, src, dest):
        if not self.isInGraph(src) or not self.isInGraph(dest):
            return True
        else: return dest in self.neighs[src]

    def generateRandomGraph(self, vertices, edges):
        for v in range(vertices):
            self.addVertex(v)
        
        generatedEdges = 0
        while generatedEdges < edges:
            src = randint(0, vertices - 1)
            dest = randint(0, vertices - 1)
            if src == dest or self.existsEdge(src, dest):
                continue
            else:
                self.addEdge(src, dest)
                generatedEdges += 1

g = Graph()
vertices = 2000
g.generateRandomGraph(vertices, vertices*10)

# print("Outbound vertices")
# for x in g.parseX(): # this parses all vertices
#         line = str(x) + " :"
#         for y in g.getOutboundVertices(x):
#             line = line + " " + str(y)
#         print(line)

# print("Inbound vertices")
# for x in g.parseX(): # this parses all vertices
#         line = str(x) + " :"
#         for y in g.getInboundVertices(x):
#             line = line + " " + str(y)
#         print(line)


# timer
t0 = time.time_ns()
for x in g.parseX():
    
    g.getOutboundVertices(x)
t1 = time.time_ns()
for x in g.parseX():    
    g.getInboundVertices(x)
t2 = time.time_ns()

print("Inbound time: " + str((t2-t1) / 1000) + " Outbound time: " + str((t1-t0) / 1000))