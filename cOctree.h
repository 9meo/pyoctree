
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string>
#include <sstream>
#include <algorithm> // find

using namespace std;

class cOctNode {
public:

    double size;
    int MAX_OCTNODE_OBJECTS;
    int NUM_BRANCHES_OCTNODE;    
    int level;
    string nid;
    vector<double> position;
    vector<cOctNode> branches;
    vector<int> data;
    vector<double> low, upp;
    cOctNode();
    cOctNode(int _level, string _nid, vector<double> _position, double _size);
    ~cOctNode();
    bool isLeafNode();
    int numPolys();
    void addPoly(int _indx);
    void addNode(int _level, string _nid, vector<double> _position, double _size);
    void getLowUppVerts();
    void setupConstants();
};

class cTri {
public:

    double D;
    int label;
    vector<vector<double> > vertices;
    vector<double> N;
    vector<double> lowVert, uppVert;
    cTri();
    cTri(int _label, vector<vector<double> > _vertices);
    ~cTri();
    void getN();
    void getD();
    bool isInNode(cOctNode &node);
    bool isInNode(vector<vector<double> > &lowUppVerts);
    void getLowerVert();
    void getUpperVert();
};

class cOctree {
public:

    int MAX_OCTREE_LEVELS;
    int branchOffsets[8][3];
    cOctNode root;
    vector<vector<double> > vertexCoords3D;
    vector<vector<int> > polyConnectivity;
    vector<cTri> polyList;
    cOctree(vector<vector<double> > _vertexCoords3D, vector<vector<int> > _polyConnectivity);
    ~cOctree();    
    double getSizeRoot();
    int numPolys();
    vector<double> getPositionRoot();
    void insertPoly(cOctNode &node, cTri &poly);
    void insertPolys();
    void setupPolyList();
    void splitNodeAndReallocate(cOctNode &node);
    cOctNode* getNodeFromLabel(int polyLabel);
	cOctNode* findBranch(int polyLabel, cOctNode &node);
};

class CLine {
public:
    vector<double> p0,p1,dir;
    CLine();
    CLine(vector<double> &lp0, vector<double> &p1_dir, int isp1orDir);
    ~CLine();
    void getDir();
    void getP1();
};

// Function prototypes
double dotProduct( vector<double> &v1, vector<double> &v2 );
double distBetweenPoints(vector<double> &p1, vector<double> &p2);
string NumberToString( int Number );
vector<double> crossProduct( vector<double> &v1, vector<double> &v2 );
vector<double> vectAdd( vector<double> &a, vector<double> &b);
vector<double> vectAdd( vector<double> &a, vector<double> &b, double sf);
vector<double> vectSubtract( vector<double> &a, vector<double> &b );

