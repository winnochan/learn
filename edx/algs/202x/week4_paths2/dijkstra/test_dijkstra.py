from dijkstra import Vertex

def test_vertex():
    v1 = Vertex(1, {}, 2)
    v2 = Vertex(1, {}, 3)
    assert(v1 < v2)
    assert(v1 <= v2)
    assert(v2 > v1)
    assert(v2 >= v1)
