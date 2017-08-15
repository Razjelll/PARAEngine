#include "ObjLoader.hpp"
#include <fstream>

#include <sstream>
#include <vector>


using namespace Para;

const std::string COMMENT = "#";
const std::string VERTICES = "v";
const std::string TEXTURE_COORD = "vt";
const std::string NORMALS = "vn";
const std::string FACES = "f";
const std::string NAME = "o";
const std::string SPACE = " ";

ObjLoader::ObjLoader()
{
}


ObjLoader::~ObjLoader()
{
}

Mesh* ObjLoader::load(const std::string& filename)
{
	std::string meshName;
	std::ifstream inputStream(filename.c_str(), std::ios::in);
	if (!inputStream)
	{
		return false;
	}

	std::string line;

	bool hasNormals = false;
	bool hasUVs = false;
	//bool isNewMesh = true; //na razie to jest niepotrzebne

	std::vector<Vec3> vertices;
	std::vector<Vec3> normals;
	std::vector<Vec2> uvs;

	std::vector<Face> faces;

	int total_triangle = 0;

	while (std::getline(inputStream, line))
	{

		// TODO dobrze przemyœleæ w którym miejscu powinnniœmy wstawiæ komentarz
		if (line.find_first_of(COMMENT) != std::string::npos)
		{
			continue;
		}

		int space_index = line.find_first_of(SPACE);
		std::istringstream stringStream(line);
		std::string prefix;
		stringStream >> prefix;

		if (prefix == VERTICES)
		{
			//TODO tutaj sprawdaæ czy jest nowa siatka
			Vec3 v;
			stringStream >> v.x;
			stringStream >> v.y;
			stringStream >> v.z;
			vertices.push_back(v);

			//TODO mo¿na tutaj jeszcze dorobiæ wyszukiwanie najmniejszej i najwiêkszej wartoœci wierzcho³ków
		}
		else if (prefix == NORMALS)
		{
			Vec3 v;
			stringStream >> v.x;
			stringStream >> v.y;
			stringStream >> v.z;
			normals.push_back(v);
			hasNormals = true;
		}
		else if (prefix == TEXTURE_COORD)
		{
			Vec2 uv;
			stringStream >> uv.x;
			stringStream >> uv.y;
			uvs.push_back(uv);
			hasUVs = true;
		}
		else if (prefix == FACES)
		{
			char separator;
			Face f;
			//je¿eli siatka zosta³a opisana za pomoc¹ trójk¹tów
			//zmniejszamy wszystkie indeksy o 1
			//TODO sprawdziæ czy to bêdzie dzia³aæ
			stringStream >> f.a; f.a--;
			stringStream >> separator; //pobieramy znak separatora "/"
			if (hasUVs) { stringStream >> f.g; f.g--; }
			stringStream >> separator;
			if (hasNormals) { stringStream >> f.d; f.d--; }
			
			stringStream >> f.b; f.b--; 
			stringStream >> separator;
			if (hasUVs) { stringStream >> f.h; f.h--; }
			stringStream >> separator;
			if (hasNormals) { stringStream >> f.e; f.e--; }
			
			stringStream >> f.c; f.c--;
			stringStream >> separator;
			if (hasUVs) { stringStream >> f.i; f.i--; }
			stringStream >> separator;
			if (hasNormals) { stringStream >> f.f; f.f--; }

			faces.push_back(f);

			total_triangle++;
		} else if (prefix == NAME)
		{
			stringStream >> meshName;
		}
		//TODO dorobiæ resztê prefixów
	}

	inputStream.close();

	std::vector<Vertex> vertexVector;
	for (int i = 0; i < faces.size(); i++)
	{
		Vertex vertex;
		vertex.position = vertices[faces[i].a];
		if (hasNormals) vertex.normal = normals[faces[i].d];
		if (hasUVs) vertex.uv = uvs[faces[i].g];
		vertexVector.push_back(vertex);

		vertex.position = vertices[faces[i].b];
		if (hasNormals) vertex.normal = normals[faces[i].e];
		if (hasUVs) vertex.uv = uvs[faces[i].h];
		vertexVector.push_back(vertex);

		vertex.position = vertices[faces[i].c];
		if (hasNormals) vertex.normal = normals[faces[i].f];
		if (hasUVs) vertex.uv = uvs[faces[i].i];
		vertexVector.push_back(vertex);
	}
	Mesh* mesh = new Mesh();
	mesh->setVertices(vertexVector);
	mesh->setName(meshName);

	vertices.clear();
	normals.clear();
	uvs.clear();

	return mesh;
}